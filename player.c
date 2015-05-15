#include "play.h"
#include "game.h"

int main(int argc,char **argv){
    struct game stratego;
    int piece[NBPIECES]={9,7,6,5,8,12,7,9,12,7,12,9,9,4,10,6,8,3,2,9,12,6,9,5,11,12,4,8,12,6,4,1,8,5,3,9,8,7,9,5};
    char buffer[BUFSIZE];
    char bufsended[BUFSIZE];
    char bufreceived[BUFSIZE];
    read(0,buffer,BUFSIZE);
    int playerNumber=buffer[0]-'0';
    if(playerNumber==1){
        swap_side(piece,NBPIECES);
    }
    for(int i=0;i<NBPIECES;i++){
        char tmp[BUFSIZE];
        sprintf(tmp,"%d\n",piece[i]);
        write(1,tmp,(piece[i]<10)?2:3);
    }
    size_t sz=read(0,buffer,BUFSIZE);
    buffer[sz-1]='\0';
    if(strcmp(buffer,"KO")==0){
        fprintf(stderr,"Bad placement\n");
        return EXIT_FAILURE;
    }
    else if(strcmp(buffer,"OK")==0){
        fprintf(stderr,"Good placement\n");
    }
    else{
        fprintf(stderr,"What ?!\n");
        return EXIT_FAILURE;
    }
    create_game(&stratego);
    init_game(&stratego,playerNumber,piece);
    print_game(&stratego);
    bool hasPlayed=false;
	if(playerNumber==0){
        select_move(&stratego,playerNumber,bufsended);
		send_move(bufsended);
		fprintf(stderr,"Sended as player 0:\n%s\n",bufsended);
		hasPlayed=true;
	}
    while(true){
        receive_move(bufreceived);
        fprintf(stderr,"Received:\n%s\n",bufreceived);
        if(hasPlayed){
            strcat(bufsended,bufreceived);
            hasPlayed=false;
        }
        else{
            strcpy(bufsended,bufreceived);
        }
        if(bufsended[7]=='F'){
            fprintf(stderr,"Failure code get\nShut Down\n");
            return EXIT_FAILURE;
        }
        else if(bufsended[7]=='E'){
            fprintf(stderr,"Error code get\nShut Down\n");
            return EXIT_FAILURE;
        }
        move_piece(&stratego,bufsended);
        print_game(&stratego);
        select_move(&stratego,playerNumber,bufsended);
        send_move(bufsended);
        fprintf(stderr,"Sended:\n%s\n",bufsended);
        hasPlayed=true;
    }
    return EXIT_SUCCESS;
}
