#include "management.h"
//function to check the position of player pieces
void check_player_piece(int piece*, int player){
	int=0;	
	for (i=0; i<39; i++){
		//If one of the cell is empty, it send KO to the player and exit
		if (pieces[i]=NULL){
			write(player, "KO", 3);
			return EXIT_FAILURE;
		}
	}
	write(player, "OK", 3);
}

//function to check player move. Return "N"(Nothing) if it work, or "B"(Battle)
void check_move(char *playerMove){
	}

//Make turn, at 0.5 of interval
void turn(int player0, int player1, char *buf){
	char player0Move=read(player0,buf,10);
	//Check if the player move is empty. If it is, return an error "E", and the other player win.
	if (strcmp(player0Move,"\0"){
		write(player0,"E",2);
		write(player1,"F",2);
		printf("Player 1 win");
		return EXIT_FAILURE;
	}
	check_move(player1Move);
	char player1Move=read(player1,buf,10);
	if (strcmp(player1Move,"\0"){
		write(player1,"E",2);
		write(player0,"F",2);
		printf("Player 0 win");
		return EXIT_FAILURE;
	}
	check_move(player0Move);
	alarm(0.5);
}
	
	
