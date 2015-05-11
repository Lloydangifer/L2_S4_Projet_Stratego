#ifndef GAME_H
#define GAME_H

#define DIMENSION 10

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct game{
    int board[DIMENSION][DIMENSION];
};

void create_game(struct game *stratego); // initialize the board with empty cells and 2 lakes
void init_game(struct game *stratego,size_t playerNumber,int *piece); // place the pieces based on the player's number
void swap_side(int *piece,size_t size); //swap the piece order, the piece most left become the piece most right
void print_game(const struct game *stratego); // print the board, we use it for debug

#endif
