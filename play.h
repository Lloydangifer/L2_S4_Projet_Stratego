#ifndef PLAY_H
#define PLAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "game.h"

#define BUFSIZE 1024

void set_North(struct direction *dir); // set a direction to North
void set_South(struct direction *dir); // set a direction to South
void set_East(struct direction *dir); // set a direction to East
void set_West(struct direction *dir); // // set a direction to West
bool position_is_correct(const size_t x,const size_t y); // check if a position is correct to receive a piece
bool position_is_available(const struct game *stratego,const size_t x,const size_t y); // check if a position is not occupied by a team member
bool position_is_valid(const struct game *stratego, const size_t x,const size_t y); //check if a position is valid
void select_first_movable_piece(const struct game *stratego,struct piece *p,struct direction *dir); // this function set p to the first movable piece of the team found
void select_strongest_movable_piece(const struct game *stratego,size_t playerNumber,struct piece *p,struct direction *dir); // search for the strongest movable piece of the team on the board
void convert_position(struct position pos,char *buffer); // convert a position to a sendable format to the referee
void select_move(const struct game *stratego,size_t playerNumber);
void move_piece();
void send_piece();
void convert_position(struct position pos,char *buffer);

#endif
