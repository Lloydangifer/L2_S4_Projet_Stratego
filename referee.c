#include "game.h"
#include "management.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#define BUFSIZE 1024  
int main(int argc, char **argv){
	if(argc!=3){
		fprintf(stderr,"The program need two argument. "); //The referee need three arguments (him and the two players). If there's a different number argument, the programs exit.
		return EXIT_FAILURE;
	}

	int play0In[2]; //File descriptor for the input of player 0
	pipe(play0In);	//Pipe of the file descriptor above
	int play0Out[2]; //File descriptor for the output of player 0
	pipe(play0Out); //Pipe of the file descriptor above
	int play1In[2]; //File descriptor for the input of player 1
	pipe(play1In); //Pipe of the file descriptor above
	int play1Out[2]; //File descriptor for the output of player 1
	pipe(play1Out); //Pipe of the file descriptor above

	char bufGood[BUFSIZE]="OK"; //Buffer for the message display if there's no error
	char bufBad[BUFSIZE]="KO"; //Buffer for the message display if there's an error
	
	char play0Path[BUFSIZE];
	sprintf(play0Path,"%s",argv[1]);
	printf("Path : %s\n",play0Path);
	char play1Path[BUFSIZE];
	sprintf(play1Path,"%s",argv[2]);
	printf("Path : %s\n",play1Path);
	
	printf("Player 0 :%s\nPlayer 1 : %s\n",argv[1], argv[2]); //Display the player. The first player in the arguments is Player 0, and the seconde player in the arguments is Player 1
	
	if(fork()==0){
		// Joueur 0
		close(play1In[0]);
		close(play1In[1]);
		close(play1Out[0]);
		close(play1Out[1]);
		dup2(play0In[0],STDIN_FILENO); 
		dup2(play0Out[1],STDOUT_FILENO);
		execv(play0Path,argv);
	}else{
		if(fork()==0){
			// Joueur 1

			close(play0In[0]);
			close(play0In[1]);
			close(play1Out[0]);
			close(play1Out[1]);
			dup2(play1In[0],STDIN_FILENO);
			dup2(play1Out[1],STDOUT_FILENO);
			execv(play1Path,argv);
		}
		// Attente du joueur 0
 
		write(play0In[1],bufGood,3);
 
		wait(NULL);
		read(play0Out[0],bufGood,3);
		printf("Message reçu = \"%s\"\n", bufGood);

		// Attente du joueur 1

		write(play1In[1],bufBad,3);

		wait(NULL);
		read(play1Out[0],bufBad,3);
		printf("Message reçu = \"%s\"\n", bufBad);
	}
    return EXIT_SUCCESS;
}
