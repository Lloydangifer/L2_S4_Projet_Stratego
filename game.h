#ifndef GAME_H
#define GAME_H

#define DIMENSION 10
#define NBPIECES 40

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdbool.h>

struct square{
    size_t value;
    bool team;
};
struct game{
    struct square board[DIMENSION][DIMENSION];
};
struct position{
    size_t posX;
    size_t posY;
};
struct direction{
    int dirX;
    int dirY;
    char value;
};
struct piece{
    size_t value;
    struct position pos;
};

void create_game(struct game *stratego); // initialize the board with empty cells and 2 lakes
void init_game(struct game *stratego,size_t playerNumber,int *piece); // place the pieces based on the player's number
void swap_side(int *piece,size_t size); //swap the piece order, the piece most left become the piece most right
void print_game(const struct game *stratego); // print the board, we use it for debug
void update_game(struct game *stratego,struct position pos,struct direction dir,size_t range,bool selfDestruct); //update the board by moving a piece

#endif
