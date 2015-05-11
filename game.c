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
void init_game(struct game *stratego,size_t playerNumber, int *piece){ // place the pieces based on the player's number
    assert(playerNumber<2);
    int i=0;
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
