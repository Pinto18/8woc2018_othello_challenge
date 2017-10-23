//Implementation For Player Class
 #include "player.hpp"

Player::Player(char playerColor, string playerName)
{
   this->color = playerColor;
   this->name = playerName;
}

int Player::setColor(char colorChar)
{
   this->color = colorChar;
   return 0;
}

int Player::setName(string playerName)
{
   this->name = playerName;
   return 0;
}
