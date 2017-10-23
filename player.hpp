//Header File for Player Class
#ifndef PLAYER_H
#define PLAYER_H
//#include "piece.hpp"
#include <iostream>
using namespace std;

class Player
{
   public:
      Player(char, string);
      char getColor(){return this->color;};
      int setColor(char);
      string getName(){return this->name;};
      int setName(string);
   private:
      char color;
      string name;
      //int turn();
};
#endif
