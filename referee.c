#include "game.h"
#include "management.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFSIZE 1024  

int main(int argc, char **argv){
	if(argc!=3){
		fprintf(stderr,"The program need two argument. "); //The referee need three arguments (him and the two players). If there's a different number argument, the programs exit.
		return EXIT_FAILURE;
	}
	//We open the log file (or create it if they don't exist)
	int log0 = creat("player0.log",S_IRWXU|S_IRGRP|S_IROTH);
	int log1 = creat("player1.log",S_IRWXU|S_IRGRP|S_IROTH);

	//char bufGood[BUFSIZE]="OK"; //Buffer for the message display if there's no error
	//char bufBad[BUFSIZE]="KO"; //Buffer for the message display if there's an error
	
	//Path of player 0
	char play0Path[BUFSIZE];
	sprintf(play0Path,"%s",argv[1]);
	printf("Path Player 0 : %s\n",play0Path);
	//Path of player 1
	char play1Path[BUFSIZE];
	sprintf(play1Path,"%s",argv[2]);
	printf("Path Player 1: %s\n",play1Path);
	
	printf("Player 0 :%s\nPlayer 1 : %s\n",argv[1], argv[2]); //Display the player. The first player in the arguments is Player 0, and the seconde player in the arguments is Player 1
	
	int play0In[2]; //File descriptor for the input of player 0
	pipe(play0In);	//Pipe of the file descriptor above
	int play0Out[2]; //File descriptor for the output of player 0
	pipe(play0Out); //Pipe of the file descriptor above
	
	//Fork player 0
	if(fork()==0){
		//We redirect the standard input and stadard output, then we close the pipe
		dup2(play0In[0],0); 
		dup2(play0Out[1],1);
		dup2(log0, 2);
		close(play0In[1]);
		close(play0Out[0]);
		close(play0In[0]);
		close(play0Out[1]);
		//close(log0);
		//We execute the program of Player 0. If there's a problem --> EXIT_FAILURE
		execv(play0Path,argv);
		return EXIT_FAILURE;
	}
	//We close unused pipe
	close(play0In[0]);
	close(play0Out[1]);

	int play1In[2]; //File descriptor for the input of player 1
	pipe(play1In); //Pipe of the file descriptor above
	int play1Out[2]; //File descriptor for the output of player 1
	pipe(play1Out); //Pipe of the file descriptor above
	
	//Fork Player 1
	if(fork()==0){
		//We redirect the standard input and stadard output, then we close the pipe
		dup2(play1In[0],0);
		dup2(play1Out[1],1);
		dup2(log1,2);
		close(play1In[1]);
		close(play1Out[0]);
		close(play1In[0]);
		close(play1Out[1]);
		//We execute the program of Player 1. If there's a problem --> EXIT_FAILURE
		execv(play1Path,argv);
		return EXIT_FAILURE;
	}
	//We close unused pipe
	close(play1In[0]);
	close(play1Out[1]);

	int play0Input=play0In[1];
	int play0Output=play0Out[0];
	int play1Input=play1In[1];
	int play1Output=play1Out[0];
	//We give to the players their number
	write(play0Input,"0",2);
	write(play1Input,"1",2);
	wait(NULL);
	//Change SIGALARM to the function  turn
	signal(SIGALRM, turn);
	//Set alarm to 0.5s
	alarm(0.5);
	//We close the log file
	close(log0);
	close(log1);
    return EXIT_SUCCESS;
}
