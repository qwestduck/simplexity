#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef int color_t;
#define PLAYER_RED   0
#define PLAYER_WHITE 1
#define STATUS_OK    0

extern bool _seeded;

class Player {
public:
  Player();
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
  RandomPlayer(Board* board, color_t color);
  status_t move();
};
#endif
