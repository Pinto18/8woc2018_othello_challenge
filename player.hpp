//Header File for Player Class

//#include "piece.hpp"
#include <iostream>
using namespace std;

class Player
{
   public:
      Player();
      char getColor(){return this->color;};
      int setColor(char);
      string getName(){return this->name;};
      int setName(string);
   private:
      char color;
      string name;
      //int turn();
};
