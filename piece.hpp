//Header File for Piece Class
#ifndef PIECE_H
#define PIECE_H
class Piece
{
   public:
      Piece(char);
      int setColor(char);
      int setPosition(int, int);
      char getColor(){return this->color;};
      int getRowCoordinate(){return this->rowCoordinate;};
      int getColumnCoordinate(){return this->columnCoordinate;};
      int flip();
   private:
      char color;
      int rowCoordinate;
      int columnCoordinate;
};
#endif
