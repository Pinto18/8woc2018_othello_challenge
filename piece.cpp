//Implementation for Piece Class

#include "piece.hpp"
#include <iostream>
using namespace std;

Piece::Piece(char initColor)
{
   this->color = initColor;
   this->rowCoordinate = 0;
   this->columnCoordinate = 0;
}

int Piece::setColor(char colorChar)
{
   this->color = colorChar;
   if(colorChar != 'B' || colorChar != 'b')
      if(colorChar != 'W' || colorChar != 'w')
         if(colorChar != ' ')
            cout << "ERROR: Invalid character for piece color!" << endl;
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
   else
      this->setColor('B');
   return 0;
}
