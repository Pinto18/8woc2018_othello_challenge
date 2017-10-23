//Implememntation of the Board Class

#include <iostream>
#include "board.hpp"

Board::Board()
{
   for(int rowIndex = 0; rowIndex <= 3; rowIndex++)
   {
      for(int columnIndex = 0; columnIndex <= 3; columnIndex++)
      {
         if(rowIndex == 1 && columnIndex == 1)
            this->pieces[rowIndex][columnIndex] = new Piece('W');
        else if(rowIndex == 2 && columnIndex == 2)
           this->pieces[rowIndex][columnIndex] = new Piece('W');
        else if(rowIndex == 1 && columnIndex == 2)
           this->pieces[rowIndex][columnIndex] = new Piece('B');
        else if(rowIndex == 2 && columnIndex == 1)
           this->pieces[rowIndex][columnIndex] = new Piece('B');
        else
           this->pieces[rowIndex][columnIndex] = new Piece(' ');
      }
   }
}
Board::~Board()
{
   for(int rowIndex = 0; rowIndex <= 3; rowIndex++)
      for(int columnIndex = 0; columnIndex <= 3; columnIndex++)
         delete pieces[rowIndex][columnIndex];
}

int Board::draw()
{
   cout << "\t_______________________________" << endl;
   for(int rowIndex = 0; rowIndex <= 3; rowIndex++)
   {
      cout << "\t";
      for(int columnIndex = 0; columnIndex <= 3; columnIndex++)
      {
         cout << pieces[rowIndex][columnIndex] << "|";
      }
      cout << endl;
   }
   cout << "\t_______________________________"  << endl;
   return 0;
}

bool Board::isFull()
{
   bool allSpacesOccupied = true;

   for(int rowIndex = 0; rowIndex <= 3; rowIndex++)
   {
      for(int columnIndex = 0; columnIndex <= 3; columnIndex++)
      {
         if(pieces[rowIndex][columnIndex]->getColor() == ' ')
         {
            allSpacesOccupied = false;
            break;
         }
      }
      break;
   }
   return allSpacesOccupied;
}

int Board::flipPieces( int rowCoordinate,
                int columnCoordinate,
                char playersColor
              )
{
    //checking along the column of the piece that was placed
    int pieceDistance = 0;
    int flipIndex = 0;

    for(int rowIndex = 0; rowIndex <= 3; rowIndex++)  //make sure we are not looking at the piece that was just placed
    {                                                 //or a piece that is right next to the one that was placed
       pieceDistance = abs(rowIndex - rowCoordinate);
       if((pieces[rowIndex][columnCoordinate]->getColor() == playersColor) && pieceDistance > 1)
       {
          flipIndex = rowIndex;
          if(flipIndex < rowCoordinate)
          {
             while(flipIndex < rowCoordinate)
             {
                pieces[flipIndex][columnCoordinate]->flip();
                flipIndex++;
             }
          }
          else
          {
             while(flipIndex > rowCoordinate)
             {
                pieces[flipIndex][columnCoordinate]->flip();
                flipIndex--;
             }
          }
       }
    }

    //checking along the row that the piece was placed
    for(int columnIndex = 0; columnIndex <= 3; columnIndex++)
    {
       pieceDistance = abs(columnIndex - columnCoordinate);
       if((pieces[rowCoordinate][columnIndex]->getColor() == playersColor) && pieceDistance > 1)
       {
          flipIndex = columnIndex;
          if(flipIndex < columnCoordinate)
          {
             while(flipIndex < columnCoordinate)
             {
                pieces[rowCoordinate][flipIndex]->flip();
                flipIndex++;
             }
          }
          else
          {
             while(flipIndex > columnCoordinate)
             {
                pieces[rowCoordinate][flipIndex]->flip();
                flipIndex--;
             }
          }
       }
    }
    return 0;
}

int Board::declareWinner()
{
    int darkPiecesNum = 0;
    int whitePiecesNum = 0;

    for(int rowIndex = 0; rowIndex <= 3; rowIndex++)
    {
       for(int columnIndex = 0; columnIndex <= 3; columnIndex++)
       {
          if(this->pieces[rowIndex][columnIndex]->getColor() == 'B')
             darkPiecesNum++;
          else
             whitePiecesNum++;
       }
    }
    if(darkPiecesNum > whitePiecesNum)
       cout << "Player 1 wins!" << endl;
    else if(whitePiecesNum > darkPiecesNum)
       cout << "Player 2 wins!" << endl;
    else
       cout << "It's a draw!" << endl;

   return 0;
}
