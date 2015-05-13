#ifndef PLAY_H
#define PLAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "game.h"

void set_North(struct direction *dir);
void set_South(struct direction *dir);
void set_East(struct direction *dir);
void set_West(struct direction *dir);
bool position_is_correct(const size_t x,const size_t y);
bool position_is_available(const struct game *stratego,const size_t x,const size_t y);
bool position_is_valid(const struct game *stratego, const size_t x,const size_t y);
void select_first_movable_piece(const struct game *stratego,struct piece *p,struct direction *dir);
void select_strongest_movable_piece(const struct game *stratego,size_t playerNumber,struct piece *p,struct direction *dir);
void select_move(const struct game *stratego,size_t playerNumber);
void move_piece();
void send_piece();

#endif
