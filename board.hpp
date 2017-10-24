//Header File for Board Class
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cmath>
#include "player.hpp"
#include "piece.hpp"

#define MAX_HEIGHT 4
#define MAX_WIDTH 4
using namespace std;

class Board
{
   public:
      Board();
      ~Board();
      int draw();
      int flipPieces(const int, const int, const char);
      bool isFull();
      bool isValidMove(int, int);
      int placePiece(int, int, char);
      int declareWinner();
   private:
      Piece* pieces[MAX_HEIGHT][MAX_WIDTH];
};
#endif
