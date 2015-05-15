#include "play.h"
#include "game.h"

int main(int argc,char **argv){
    struct game stratego;
    FILE *in=stdin;
    int piece[NBPIECES]={9,7,6,5,8,12,7,9,12,7,12,9,9,4,10,6,8,3,2,9,12,6,9,5,11,12,4,8,12,6,4,1,8,5,3,9,8,7,9,5};
    char *buffer=calloc(BUFSIZE,sizeof(char));
    char bufPNumber=NULL; //buffer for the player's number
    fread(&bufPNumber,sizeof(char),1,in);
    int playerNumber=bufPNumber-'0';
    if(playerNumber==1){
        swap_side(piece,NBPIECES);
    }
    for(int i=0;i<NBPIECES;i++){
        sprintf(buffer,"%d\n",piece[i]);
        send_move(buffer);
    }
    receive_move(buffer);
    if(strcmp(buffer,"KO")==0){
        fprintf(stderr,"Bad placement\nreçu%s",buffer);
        return EXIT_FAILURE;
    }
    else if(strcmp(buffer,"OK")==0){
        fprintf(stderr,"Good placement\nreçu%s",buffer);
    }
    else{
        fprintf(stderr,"What ?!\nreçu:%s",buffer);
    }
    create_game(&stratego);
    init_game(&stratego,playerNumber,piece);
	if (playerNumber==0){
        select_move(&stratego,playerNumber,buffer);
		send_move(buffer);
	}else if(playerNumber==1){
		char *str="B6\nW\n1\n";
		send_move(str);
	}
    while(1==1){
        /*for(int i=0;i<BUFSIZE;i++){
            if(buffer[i]=='\n'){

            }
        }
        if(strcmp(buffer,"F")==0){
            fprintf(stderr,"Failure code get, U mad opponent ?");
            return EXIT_FAILURE;
        }
        else if(strcmp(buffer,"E")==0){
            fprintf(stderr,"Error code get, i'm sorry...");
            return EXIT_FAILURE;
        }*/
    }
    //print_game(&stratego);
    return EXIT_SUCCESS;
}
