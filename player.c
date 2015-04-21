#include "player.h"
#include "play.h"
#include "game.h"

int main(int argc,char **argv){
    if(argc!=2){
        fprintf(stderr,"Error: one argument needed !\n");
        return EXIT_FAILURE;
    }
    size_t playerNumber=atoi(argv[1]);
    struct game stratego;
    create_game(&stratego);
    print_game(&stratego);
    init_game(&stratego,playerNumber);
    print_game(&stratego);
    return EXIT_SUCCESS;
}
