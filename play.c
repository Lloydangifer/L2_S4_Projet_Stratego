#include "play.h"

void set_North(struct direction *dir){
    dir->dirX=0;
    dir->dirY=-1;
    dir->value='N';
}
void set_South(struct direction *dir){
    dir->dirX=0;
    dir->dirY=1;
    dir->value='S';
}
void set_East(struct direction *dir){
    dir->dirX=1;
    dir->dirY=0;
    dir->value='E';
}
void set_West(struct direction *dir){
    dir->dirX=-1;
    dir->dirY=0;
    dir->value='W';
}
bool position_is_correct(const size_t x,const size_t y){ // check if a position is correct to receive a piece
    if((y<0)||(y>=DIMENSION)){ // check if the y of the position is in the board
        return false;
    }
    if((x<0)||(x>=DIMENSION)){ // check if the x of the position is in the board
        return false;
    }
    if((y==2)||(y==3)||(y==6)||(y==7)){ // check if the position is not a lake
        if((x==4)||(x==5)){
            return false;
        }
    }
    return true;
}
bool position_is_available(const struct game *stratego,const size_t x,const size_t y){ // check if a position is not occupied by a team member
    if(stratego->board[y][x].team==false){
        return true;
    }
    else{
        return false;
    }
}
bool position_is_valid(const struct game *stratego, const size_t x,const size_t y){ //check if a position is valid
    if(position_is_correct(x,y)){
        if(position_is_available(stratego,x,y)){
            return true;
        }
    }
    return false;
}
void select_first_movable_piece(const struct game *stratego,struct piece *p,struct direction *dir){
    size_t pY=0;
    size_t pX=0;
    bool filled=false;
    struct position destination;
    destination.posX=dir->dirX;
    destination.posY=dir->dirY;
    do{
        if(stratego->board[pY][pX].team==true){
            if(position_is_valid(stratego,destination.posX,destination.posY)){
                p->value=stratego->board[pY][pX].value;
                p->pos.posY=pY;
                p->pos.posX=pX;
                filled=true;
            }
        }
        pY++;
        pX++;
        destination.posX+=pX;
        destination.posY+=pY;
    }while(filled==false);
}
void select_strongest_movable_piece(const struct game *stratego,size_t playerNumber,struct piece *p,struct direction *dir){
    assert(playerNumber<2);
    select_first_movable_piece(stratego,p,dir);
    for(size_t y=0;y<DIMENSION;y++){
        for(size_t x=0;x<DIMENSION;x++){
            if(stratego->board[y][x].team==true){
                if(stratego->board[y][x].value<p->value){
                    if(position_is_valid(stratego,x+dir->dirX,y+dir->dirY)){
                        p->value=stratego->board[y][x].value;
                        p->pos.posY=y;
                        p->pos.posX=x;
                    }
                }
            }
        }
    }
}
void select_move(const struct game *stratego,size_t playerNumber){
    assert(playerNumber<2);
    struct piece p;
    struct direction dir;
    if(playerNumber==0){
        set_East(&dir);
    }
    else{
        set_West(&dir);
    }
    select_strongest_movable_piece(stratego,playerNumber,&p,&dir);

}
void move_piece(){}
void send_piece(){
    char *str="A3\nE\n1\n";
    fwrite(str, sizeof(char),8, stdout);
    fflush(stdout);
}
