#include "play.h"
#include "game.h"

bool position_is_correct(size_t x,size_t y){
    if((y<0)||(y=>DIMENSION)){
        return false;
    }
    if((x<0)||(x=>DIMENSION)){
        return false;
    }
    if((y==2)||(y==3)||(y==6)||(y==7)){
        if((x==4)||(x==5)){
            return false
        }
    }
    return true;
}
bool position_is_available(struct game stratego,size_t x,size_t y){
    if(stratego.board[y][x].team==false){
        return true;
    }
    else{
        return false;
    }
}
bool position_is_
void move_piece(){}
void select_piece(){}
 void send_piece(){

 char *str="A3\nE\n1\n";

 fwrite(str, sizeof(char),8, stdout);

   fflush(stdout);

}
