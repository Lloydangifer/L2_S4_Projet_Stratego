#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <signal.h>
#include <unistd.h>

void check_player_piece(int piece*, int player);
void check_move(char *playerMove);
void turn(int player1, int player2, char *buf);

#endif
