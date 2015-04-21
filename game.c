#include "game.h"

void create_game(struct game *stratego){ // initialize the board with empty cells and 2 lakes
    for(int y=0;y<DIMENSION;y++){
        for(int x=0;x<DIMENSION;x++){
             stratego->board[y][x]=0; // 0 mean an empty cell
        }
    }
    stratego->board[2][4]=13; // 13 mean a cell of lake
    stratego->board[2][5]=13; // 13 mean a cell of lake
    stratego->board[3][4]=13; // 13 mean a cell of lake
    stratego->board[3][5]=13; // 13 mean a cell of lake
    stratego->board[6][4]=13; // 13 mean a cell of lake
    stratego->board[6][5]=13; // 13 mean a cell of lake
    stratego->board[7][4]=13; // 13 mean a cell of lake
    stratego->board[7][5]=13; // 13 mean a cell of lake
}
void init_game(struct game *stratego,size_t playerNumber){ // place the pieces based on the player's number
    assert(playerNumber<2);
    if(playerNumber==0){
        int i=0;
        int piece[40]={9,7,6,5,8,12,7,9,12,7,12,9,9,4,10,6,8,3,2,9,12,6,9,5,11,12,4,8,12,6,4,1,8,5,3,9,8,7,9,5};
        for(int y=0;y<DIMENSION;y++){
            for(int x=0;x<4;x++){ // it only fills the left side
                stratego->board[y][x]=piece[i];
                i++;
            }
            for(int x=6;x<DIMENSION;x++){ // the right side will be filled with unknown pieces to represent the parts of the other player
                stratego->board[y][x]=14; // 14 mean a unknow piece
            }
        }
    }
    if(playerNumber==1){
        int i=0;
        int piece[40]={5,6,7,9,9,7,12,8,9,12,7,12,6,10,4,9,9,2,3,8,5,9,6,12,8,4,12,11,1,4,6,12,9,3,5,8,5,9,7,8};
        for(int y=0;y<DIMENSION;y++){
            for(int x=0;x<4;x++){ // the left side will be filled with unknown pieces to represent the parts of the other player
                stratego->board[y][x]=14; // 14 mean a unknow piece
            }
            for(int x=6;x<DIMENSION;x++){ // it only fills the right side
                stratego->board[y][x]=piece[i];
                i++;
            }
        }
    }
}
void print_game(const struct game *stratego){ // print the board, we use it for debug
    for(int y=0;y<DIMENSION;y++){
        for(int x=0;x<DIMENSION;x++){
            if(stratego->board[y][x]==10){
                printf("S ");
            }
            else if(stratego->board[y][x]==11){
                printf("F ");
            }
            else if(stratego->board[y][x]==12){
                printf("B ");
            }
            else if(stratego->board[y][x]==13){
                printf("L ");
            }
            else if(stratego->board[y][x]==14){
                printf("? ");
            }
            else{
                printf("%d ",stratego->board[y][x]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
