#ifndef PLAY_H
#define PLAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool position_is_correct(size_t x,size_t y);
bool position_is_available(struct game stratego,size_t x,size_t y);
void move_piece();
void select_piece();
void send_piece();

#endif
