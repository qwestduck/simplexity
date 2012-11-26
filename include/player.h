#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef int color_t;

class Player {
public:
  Player(Board* board, color_t color);
  virtual status_t move() = 0;
protected:
  int squaresRemaining;
  int circlesRemaining;
  color_t _color;
  Board*  _board;
};

class RandomPlayer : public Player {
public:
  status_t move();
};
#endif
