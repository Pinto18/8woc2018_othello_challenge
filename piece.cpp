//Implementation for Piece Class

#include "piece.hpp"
#include <iostream>
using namespace std;

Piece::Piece(char initColor, int rowCoordinate, int columnCoordinate)
{
   this->color = initColor;
   this->rowCoordinate = rowCoordinate;
   this->columnCoordinate = columnCoordinate;
}

int Piece::setColor(char colorChar)
{
   this->color = colorChar;
   return 0;
}

int Piece::setPosition( int rowCoordinate,
                        int columnCoordinate)
{
   this->rowCoordinate = rowCoordinate;
   this->columnCoordinate = columnCoordinate;
   return 0;
}

int Piece::flip()
{
   if(this->getColor() == 'B')
      this->setColor('W');
   else if(this->getColor() == 'W')
      this->setColor('B');
   else
      return 0;
   return 0;
}
