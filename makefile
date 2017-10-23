CC = g++
CFLAGS = -g -Wall

main: main.cpp board.cpp piece.cpp player.cpp
	$(CC) $(CFLAGS) -o main main.cpp board.cpp piece.cpp player.cpp 

