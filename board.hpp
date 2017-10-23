//Header File for Board Class
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cmath>
#include "player.hpp"
#include "piece.hpp"

using namespace std;

class Board
{
   public:
      Board();
      ~Board();
      int draw();
      int flipPieces(int, int, char);
      bool isFull();
      //int nextTurn();
      int declareWinner();
   private:
      Piece* pieces[4][4];
     //Player player1 = new Player('B');
     //Player player2 = new Player('W');
     //Player* currentPlayer;
};
#endif
