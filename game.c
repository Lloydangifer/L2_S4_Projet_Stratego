#include "game.h"

void create_game(struct game *stratego){ // initialize the board with empty cells and 2 lakes
    for(int y=0;y<DIMENSION;y++){
        for(int x=0;x<DIMENSION;x++){
             stratego->board[y][x].value=0; // 0 mean an empty cell
             stratego->board[y][x].team=false;
        }
    }
    stratego->board[2][4].value=13; // 13 mean a cell of lake
    stratego->board[2][5].value=13; // 13 mean a cell of lake
    stratego->board[3][4].value=13; // 13 mean a cell of lake
    stratego->board[3][5].value=13; // 13 mean a cell of lake
    stratego->board[6][4].value=13; // 13 mean a cell of lake
    stratego->board[6][5].value=13; // 13 mean a cell of lake
    stratego->board[7][4].value=13; // 13 mean a cell of lake
    stratego->board[7][5].value=13; // 13 mean a cell of lake
}
void init_game(struct game *stratego,size_t playerNumber, int *piece){ // place the pieces based on the player's number
    assert(playerNumber<2);
    int i=0;
    if(playerNumber==0){
        for(int y=0;y<DIMENSION;y++){
            for(int x=0;x<4;x++){ // it only fills the left side
                stratego->board[y][x].value=piece[i];
                stratego->board[y][x].team=true;
                i++;
            }
            for(int x=6;x<DIMENSION;x++){ // the right side will be filled with unknown pieces to represent the parts of the other player
                stratego->board[y][x].value=14; // 14 mean a unknow piece
                stratego->board[y][x].team=false;
            }
        }
    }
    else{
        for(int y=0;y<DIMENSION;y++){
            for(int x=6;x<DIMENSION;x++){ // it only fills the left side
                stratego->board[y][x].value=piece[i];
                stratego->board[y][x].team=true;
                i++;
            }
            for(int x=0;x<4;x++){ // the right side will be filled with unknown pieces to represent the parts of the other player
                stratego->board[y][x].value=14; // 14 mean a unknow piece
                stratego->board[y][x].team=false;
            }
        }
    }
}
void swap_side(int *piece,size_t size){ //swap the piece order, the piece most left become the piece most right
    for(int i=0;i<size;i=i+4){ // swap an entire line
            int temp=piece[i];
            piece[i]=piece[i+3];
            piece[i+3]=temp;
            temp=piece[i+1];
            piece[i+1]=piece[i+2];
            piece[i+2]=temp;
        }
}
void print_game(const struct game *stratego){ // print the board, we use it for debug
    for(int y=0;y<DIMENSION;y++){
        for(int x=0;x<DIMENSION;x++){
            if(stratego->board[y][x].value==10){
                fprintf(stderr,"S ");
            }
            else if(stratego->board[y][x].value==11){
                fprintf(stderr,"F ");
            }
            else if(stratego->board[y][x].value==12){
                fprintf(stderr,"B ");
            }
            else if(stratego->board[y][x].value==13){
                fprintf(stderr,"L ");
            }
            else if(stratego->board[y][x].value==14){
                fprintf(stderr,"? ");
            }
            else{
                fprintf(stderr,"%ld ",stratego->board[y][x].value);
            }
        }
        fprintf(stderr,"\n");
    }
    fprintf(stderr,"\n");
}
void update_game(struct game *stratego,struct position pos,struct direction dir,size_t range,bool selfDestruct){ //update the board by moving a piece
    assert((dir.dirX>0)||(dir.dirY>0));
    stratego->board[(pos.posY+(dir.dirY*range))][(pos.posX+(dir.dirX*range))].value=stratego->board[pos.posY][pos.posX].value;
    stratego->board[(pos.posY+(dir.dirY*range))][(pos.posX+(dir.dirX*range))].team=true;
    stratego->board[pos.posY][pos.posX].value=0;
    stratego->board[pos.posY][pos.posX].team=false;
    if(selfDestruct==true){
        stratego->board[(pos.posY+(dir.dirY*range))][(pos.posX+(dir.dirX*range))].value=0;
        stratego->board[(pos.posY+(dir.dirY*range))][(pos.posX+(dir.dirX*range))].team=false;
    }
}
