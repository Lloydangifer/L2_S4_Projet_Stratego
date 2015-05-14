#include "player.h"
#include "play.h"
#include "game.h"

int main(int argc,char **argv){
    struct game stratego;
    FILE *out=stdout;
    FILE *in=stdin;
    int piece[40]={9,7,6,5,8,12,7,9,12,7,12,9,9,4,10,6,8,3,2,9,12,6,9,5,11,12,4,8,12,6,4,1,8,5,3,9,8,7,9,5};
    char buffer[BUFSIZE];
    char bufPNumber=NULL; //buffer for the player's number
    fread(&bufPNumber,sizeof(char),1,in);
    int playerNumber=bufPNumber-'0';
    if(playerNumber==1){
        swap_side(piece,40);
    }
    for(int i=0;i<40;i++){
        sprintf(buffer,"%d",piece[i]);
        fwrite(buffer,sizeof(char),2,out);
        fwrite("\n",sizeof(char),1,out);
    }
    fflush(out);
    struct position pos;
    pos.posY=0;
    pos.posX=0;
    convert_position(pos,buffer);
    printf("buffer:%s\n",buffer);
    fgets(buffer,2,in);
    if(strcmp(buffer,"KO")==0){
        fprintf(stderr,"Bad placement\n");
        return EXIT_FAILURE;
    }
    else if(strcmp(buffer,"OK")==0){
        fprintf(stderr,"Good placement\n");
    }
    else{
        fprintf(stderr,"What ?!\n");
    }
    create_game(&stratego);
    init_game(&stratego,playerNumber,piece);
	if (playerNumber==0){
		send_piece();
	}else if(playerNumber==1){
		char *str="B6\nW\n1\n";
		fwrite(str, sizeof(char),8, stdout);
    		fflush(stdout);
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
