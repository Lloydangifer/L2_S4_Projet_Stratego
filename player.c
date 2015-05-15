#include "play.h"
#include "game.h"

int main(int argc,char **argv){
    struct game stratego;
    int piece[NBPIECES]={9,7,6,5,8,12,7,9,12,7,12,9,9,4,10,6,8,3,2,9,12,6,9,5,11,12,4,8,12,6,4,1,8,5,3,9,8,7,9,5};
    char *buffer=calloc(BUFSIZE,sizeof(char));
    receive_move(buffer);
    int playerNumber=buffer[0]-'0';
    if(playerNumber==1){
        swap_side(piece,NBPIECES);
    }
    for(int i=0;i<NBPIECES;i++){
        char tmp[BUFSIZE];
        sprintf(tmp,"%d\n",piece[i]);
        write(1,tmp,(piece[i]<10)?2:3);
    }
    send_move(buffer);
    receive_move(buffer);
    if(strncasecmp(buffer,"KO",2)==0){
        fprintf(stderr,"Bad placement\nreçu%s",buffer);
        return EXIT_FAILURE;
    }
    else if(strncasecmp(buffer,"OK",2)==0){
        fprintf(stderr,"Good placement\nreçu%s",buffer);
    }
    else{
        fprintf(stderr,"What ?!\nreçu:%s",buffer);
        return EXIT_FAILURE;
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
