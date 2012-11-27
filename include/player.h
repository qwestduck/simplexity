#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "common.h"

extern bool _seeded;

class Player {
public:
  Player();
  Player(Board* board, color_t color);
  virtual status_t move() = 0;
protected:
  int squaresRemaining;
  int circlesRemaining;
  static player_t numPlayers;
  player_t _id;
  color_t _color;
  Board*  _board;
};

class RandomPlayer : public Player {
public:
  RandomPlayer(Board* board, color_t color);
  status_t move();
};

class SmartPlayer : public Player {
public:
  SmartPlayer(Board* board, color_t color);
  status_t move();
};
#endif
