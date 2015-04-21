CC=gcc
CFLAGS=-Wall -std=c99 -g
EXEC=referee player

all: ${EXEC}
referee: referee.o game.o management.o
	${CC} ${CFLAGS} -o referee referee.o game.o management.o
player: player.o play.o game.o
	${CC} ${CFLAGS} -o player player.o play.o game.o
management.o : management.c management.h
	${CC} -c ${CFLAGS} -o management.o management.c
referee.o : referee.c referee.h game.h
	${CC} -c ${CFLAGS} -o referee.o referee.c
player.o: player.c player.h game.h
	${CC} -c ${CFLAGS} -o player.o player.c
play.o: play.c play.h
	${CC} -c ${CFLAGS} -o play.o play.c
game.o: game.c game.h
	${CC} -c ${CFLAGS} -o game.o game.c

clean:
	rm -f *.o

mrproper: clean
	rm -f ${EXEC}
