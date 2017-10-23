//Header File for Piece Class

class Piece
{
   public:
      Piece();
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
