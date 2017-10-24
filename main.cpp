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
   cout << endl << currentPlayer->getName() <<" (" << currentPlayer->getColor() << ") begins" << endl << endl;
   board->draw();
   while(!gameOver)
   {
      cout << endl << "Enter where you want to place your piece[x,y]: ";
      cin >> rowPosition  >> columnPosition;
      if(board->isValidMove(rowPosition, columnPosition))
      {
         board->placePiece(rowPosition, columnPosition, currentPlayer->getColor());
         board->flipPieces(rowPosition, columnPosition, currentPlayer->getColor());
         nextPlayer(player1, player2);
      }
      else
         cout << "Invalid move. Try again."  << endl;
      cout << endl;
      board->draw();
      if(board->isFull())
        gameOver = true;
     //else
     //   nextPlayer(player1, player2);
   }
   board->declareWinner();

   delete player1;
   delete player2;
   delete board;
}

int nextPlayer(Player* p1, Player* p2)
{
   if(currentPlayer == p1)
      currentPlayer = p2;
   else
      currentPlayer = p1;
   cout << endl << currentPlayer->getName() << "'s (" << currentPlayer->getColor() << ") turn" << endl << endl;
   return 0;
};
