//Implememntation of the Board Class

#include <iostream>
#include "board.hpp"

Board::Board()
{
   for(int rowIndex = 0; rowIndex <= (MAX_HEIGHT - 1); rowIndex++)
   {
      for(int columnIndex = 0; columnIndex <= (MAX_WIDTH - 1); columnIndex++)
      {
         if(rowIndex == 1 && columnIndex == 1)
            this->pieces[rowIndex][columnIndex] = new Piece('W', rowIndex, columnIndex);
        else if(rowIndex == 2 && columnIndex == 2)
           this->pieces[rowIndex][columnIndex] = new Piece('W', rowIndex, columnIndex);
        else if(rowIndex == 1 && columnIndex == 2)
           this->pieces[rowIndex][columnIndex] = new Piece('B', rowIndex, columnIndex);
        else if(rowIndex == 2 && columnIndex == 1)
           this->pieces[rowIndex][columnIndex] = new Piece('B', rowIndex, columnIndex);
        else
           this->pieces[rowIndex][columnIndex] = new Piece(' ', rowIndex, columnIndex);
      }
   }
}

Board::~Board()
{
   for(int rowIndex = 0; rowIndex <= (MAX_HEIGHT - 1); rowIndex++)
      for(int columnIndex = 0; columnIndex <= (MAX_WIDTH - 1); columnIndex++)
         delete pieces[rowIndex][columnIndex];
}

int Board::draw()
{
   cout << "\t   0   1   2   3" << endl;
   cout << "\t +---+---+---+---+" << endl;
   for(int rowIndex = 0; rowIndex <= (MAX_HEIGHT - 1); rowIndex++)
   {
      cout << "\t" << rowIndex << "| ";
      for(int columnIndex = 0; columnIndex <= (MAX_WIDTH - 1); columnIndex++)
      {
         cout << this->pieces[rowIndex][columnIndex]->getColor() << " | ";
      }
      cout << endl;
      cout << "\t +---+---+---+---+" << endl;
   }
   return 0;
}

bool Board::isFull()
{
   bool allSpacesOccupied = true;

   for(int rowIndex = 0; rowIndex <= (MAX_HEIGHT - 1); rowIndex++)
   {
      for(int columnIndex = 0; columnIndex <= (MAX_WIDTH - 1); columnIndex++)
      {
         if(pieces[rowIndex][columnIndex]->getColor() == ' ')
         {
            allSpacesOccupied = false;
         }
      }
   }
   return allSpacesOccupied;
}

int Board::flipPieces( const int rowCoordinate,
                const int columnCoordinate,
                const char playersColor
              )
{
    //Piece* checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    Piece* checkPiecePointer;
    /********************************  ROW SEARCH *************************************************/
    //search all pieces below the piece the player placed for pieces with the same color
    if(rowCoordinate < (MAX_HEIGHT - 1))
    {
       int rowIndex = rowCoordinate + 1;
       checkPiecePointer = this->pieces[rowIndex][columnCoordinate];
       while(checkPiecePointer->getColor() != playersColor && rowIndex < (MAX_HEIGHT - 1))
       {
          rowIndex++;
          if(this->pieces[rowIndex][columnCoordinate]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex][columnCoordinate];
       }
    /* for(int rowIndex = rowCoordinate; rowIndex < (MAX_HEIGHT - 1); rowIndex++)
       {
          if(this->pieces[rowIndex + 1][columnCoordinate]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex + 1][columnCoordinate];
       }
    */
       //return pointer back to original piece and flip all pieces along the way
       while(checkPiecePointer->getRowCoordinate() != rowCoordinate)
       {
          checkPiecePointer = pieces[checkPiecePointer->getRowCoordinate() - 1][columnCoordinate];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate() + 1][checkPiecePointer->getColumnCoordinate()]->getColor() != ' ')
             checkPiecePointer->flip();
       }
    }

    //check all rows above the piece the player placed
    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    if(rowCoordinate > 0)
    {
       int rowIndex = rowCoordinate - 1;
       checkPiecePointer = this->pieces[rowIndex][columnCoordinate];
       while(checkPiecePointer->getColor() != playersColor && rowIndex > 0)
       {
          rowIndex--;
          if(this->pieces[rowIndex][columnCoordinate]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex][columnCoordinate];
       }
    /* for(int rowIndex = rowCoordinate; rowIndex >= 1; rowIndex--)
       {
          if(this->pieces[rowIndex - 1][columnCoordinate]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex - 1][columnCoordinate];
       }
    */
       //return pointer to original place and flip all pieces along the way
       while(checkPiecePointer->getRowCoordinate() != rowCoordinate)
       {
          checkPiecePointer = pieces[checkPiecePointer->getRowCoordinate() + 1][columnCoordinate];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate() - 1][checkPiecePointer->getColumnCoordinate()]->getColor() != ' ')
             checkPiecePointer->flip();
       }
    }
    /************************ END ROW SEARCH *******************************************************/

    /***************************** COLUMN SEARCH ***************************************************/
    //check all columns to the right of the piece the player placed
    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    if(columnCoordinate < (MAX_WIDTH - 1))
    {
       int columnIndex = columnCoordinate + 1;
       checkPiecePointer = this->pieces[rowCoordinate][columnIndex];
       while(checkPiecePointer->getColor() != playersColor && columnIndex < (MAX_WIDTH - 1))
       {
          columnIndex++;
          if(this->pieces[rowCoordinate][columnIndex]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowCoordinate][columnIndex];
       }
    /* for(int columnIndex = columnCoordinate; columnIndex < (MAX_WIDTH - 1); columnIndex++)
       {
          if(this->pieces[rowCoordinate][columnIndex + 1]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowCoordinate][columnIndex + 1];
       }
    */
       while(checkPiecePointer->getColumnCoordinate() != columnCoordinate)
       {
          checkPiecePointer = pieces[rowCoordinate][checkPiecePointer->getColumnCoordinate() - 1];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate()][checkPiecePointer->getColumnCoordinate() + 1]->getColor() != ' ')
             checkPiecePointer->flip();
       }
    }
    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    //check all columns to the left of the piece the player placed
    if(columnCoordinate > 0)
    {
       int columnIndex = columnCoordinate - 1;
       checkPiecePointer = this->pieces[rowCoordinate][columnIndex];
       while(checkPiecePointer->getColor() != playersColor && columnIndex > 0)
       {
          columnIndex--;
          if(this->pieces[rowCoordinate][columnIndex]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowCoordinate][columnIndex];
       }
    /* for(int columnIndex = columnCoordinate; columnIndex > 1; columnIndex--)
       {
          if(this->pieces[rowCoordinate][columnIndex - 1]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowCoordinate][columnIndex - 1];
       }
    */
       while(checkPiecePointer->getColumnCoordinate() != columnCoordinate)
       {
          checkPiecePointer = pieces[rowCoordinate][checkPiecePointer->getColumnCoordinate() + 1];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate()][checkPiecePointer->getColumnCoordinate() - 1])
             checkPiecePointer->flip();
       }
    }
    /************************** END COLUMN SEARCH **************************************************/

    /*********************************** DIAGNOL SEARCH ********************************************/

    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    //Checking downard and to the left
    if(rowCoordinate < (MAX_HEIGHT - 1) && columnCoordinate > 0)
    {
       int rowIndex = rowCoordinate + 1;
       int columnIndex = columnCoordinate - 1;
       checkPiecePointer = this->pieces[rowIndex][columnIndex];
       while(checkPiecePointer->getColor() != playersColor && rowIndex < (MAX_HEIGHT - 1) && columnIndex > 0)
       {
          rowIndex++;
          columnIndex--;
          if(this->pieces[rowIndex][columnIndex]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex][columnIndex];
       }
   /*
       for( int rowIndex = rowCoordinate, columnIndex = columnCoordinate;
            rowIndex < (MAX_HEIGHT - 1) && columnIndex > 1;
            rowIndex++, columnIndex--)
       {
          if(this->pieces[rowIndex + 1][columnIndex - 1]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex + 1][columnIndex - 1];
       }
    */
       while(checkPiecePointer->getRowCoordinate() != rowCoordinate && checkPiecePointer->getColumnCoordinate() != columnCoordinate)
       {
          checkPiecePointer = pieces[checkPiecePointer->getRowCoordinate() - 1][checkPiecePointer->getColumnCoordinate() + 1];
           if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate() + 1][checkPiecePointer->getColumnCoordinate() - 1]->getColor() != ' ')
             checkPiecePointer->flip();
       }
    }
    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    //checking downward and to the right
    if(rowCoordinate < (MAX_HEIGHT - 1) && columnCoordinate < (MAX_WIDTH - 1))
    {
       int rowIndex = rowCoordinate + 1;
       int columnIndex = columnCoordinate + 1;
       checkPiecePointer= this->pieces[rowIndex][columnIndex];
       while(checkPiecePointer->getColor() != playersColor && rowIndex < (MAX_HEIGHT - 1) && columnIndex < (MAX_WIDTH - 1))
       {
          rowIndex++;
          columnIndex++;
          if(this->pieces[rowIndex][columnIndex]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex][columnIndex];
       }
    /*
       for( int rowIndex = rowCoordinate, columnIndex = columnCoordinate;
            rowIndex < (MAX_HEIGHT - 1) && columnIndex < (MAX_WIDTH - 1);
            rowIndex++, columnIndex++)
       {
          if(this->pieces[rowIndex + 1][columnIndex + 1]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex + 1][columnIndex + 1];
       }
    */
       while(checkPiecePointer->getRowCoordinate() != rowCoordinate && checkPiecePointer->getColumnCoordinate() != columnCoordinate)
       {
          checkPiecePointer = pieces[checkPiecePointer->getRowCoordinate() - 1][checkPiecePointer->getColumnCoordinate() - 1];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate() + 1][checkPiecePointer->getColumnCoordinate() + 1]->getColor() != ' ')
             checkPiecePointer->flip();
       }
    }
    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    //checking upwards and to the left
    if(rowCoordinate > 0 && columnCoordinate > 0)
    {
       int rowIndex = rowCoordinate - 1;
       int columnIndex = columnCoordinate - 1;
       checkPiecePointer = this->pieces[rowIndex][columnIndex];
       while(checkPiecePointer->getColor() != playersColor && rowIndex > 0 && columnIndex > 0)
       {
          rowIndex--;
          columnIndex--;
          if(this->pieces[rowIndex][columnIndex]->getColor() ==playersColor)
             checkPiecePointer = this->pieces[rowIndex][columnIndex];
       }
    /*
       for( int rowIndex = rowCoordinate, columnIndex = columnCoordinate;
            rowIndex >= 1 && columnIndex >= 1;
            rowIndex--, columnIndex--)
       {
          if(this->pieces[rowIndex - 1][columnIndex - 1]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex- 1][columnIndex - 1];
       }
    */
       while(checkPiecePointer->getRowCoordinate() != rowCoordinate && checkPiecePointer->getColumnCoordinate() != columnCoordinate)
       {
          checkPiecePointer = pieces[checkPiecePointer->getRowCoordinate() + 1][checkPiecePointer->getColumnCoordinate() + 1];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate() - 1][checkPiecePointer->getColumnCoordinate() - 1]->getColor() != ' ')
            checkPiecePointer->flip();
       }
    }
    //checkPiecePointer = this->pieces[rowCoordinate][columnCoordinate];
    //checking upwards and to the right
    if(rowCoordinate > 0 && columnCoordinate < (MAX_WIDTH - 1))
    {
       int rowIndex = rowCoordinate - 1;
       int columnIndex = columnCoordinate + 1;
       checkPiecePointer = this->pieces[rowIndex][columnIndex];
       while(checkPiecePointer->getColor() != playersColor && rowIndex > 0 && columnIndex < (MAX_WIDTH - 1))
       {
          rowIndex--;
          columnIndex++;
          if(this->pieces[rowIndex][columnIndex]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex][columnIndex];
       }
    /*
       for( int rowIndex = rowCoordinate, columnIndex = columnCoordinate;
            rowIndex >= 1 && columnIndex < (MAX_WIDTH - 1);
            rowIndex--, columnIndex++)
       {
          if(this->pieces[rowIndex - 1][columnIndex + 1]->getColor() == playersColor)
             checkPiecePointer = this->pieces[rowIndex - 1][columnIndex + 1];
       }
    */
       while(checkPiecePointer->getRowCoordinate() != rowCoordinate && checkPiecePointer->getColumnCoordinate() != columnCoordinate)
       {
          checkPiecePointer = pieces[checkPiecePointer->getRowCoordinate() + 1][checkPiecePointer->getColumnCoordinate() - 1];
          if(checkPiecePointer->getColor() != playersColor && this->pieces[checkPiecePointer->getRowCoordinate() - 1][checkPiecePointer->getColumnCoordinate() + 1]->getColor() != ' ')
             checkPiecePointer->flip();
       }
    }
    /************************************ END DIAGNOL SEARCH ***************************************/
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

int Board::placePiece(int rowCoordinate, int columnCoordinate, char playersColor)
{
   this->pieces[rowCoordinate][columnCoordinate]->setColor(playersColor);
   return 0;
}
