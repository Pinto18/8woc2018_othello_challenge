#include <iostream>
#include "board.hpp"
#include "piece.hpp"
#include "player.hpp"

using namespace std;
int nextPlayer(Player*, Player*);
Player* currentPlayer;

int main()
{
   Player* player1 = new Player('B', "Player 1");
   Player* player2 = new Player('W', "Player 2");
   Board*  board = new Board();
   bool gameOver = false;
   int rowPosition, columnPosition;

   cout << "Welcome to Othello!" << endl << endl;
   currentPlayer = player1;
   while(!gameOver)
   {
      board->draw();
      cout << "Enter where you want to place your piece[x,y]: ";
      cin >> rowPosition  >> columnPosition;
      board->placePiece(rowPosition, columnPosition, currentPlayer->getColor());
      board->flipPieces(rowPosition, columnPosition, currentPlayer->getColor());
      board->draw();
      if(board->isFull())
        gameOver = true;
     else
        nextPlayer(player1, player2);
   }
   board->declareWinner();

   delete player1;
   delete player2;
   delete board;
}

int nextPlayer(Player* p1, Player* p2)
{
   if(currentPlayer == p1)
   {
      currentPlayer = p2;
      cout << "Player 2's turn" << endl <<endl;
   }
   else
   {
      currentPlayer = p1;
      cout << "Player 1's turn" << endl << endl;
   }
   return 0;
};
