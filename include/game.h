#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

typedef int player_t;

class Game {
public:
  Game();
  void play();
  player_t winner();
  int moves();
protected:
  virtual void init() = 0;
  Board* _board;
  Player* _p1;
  Player* _p2;
  player_t _winner;
  int _moves;
};

class RvRGame : public Game {
public:
  RvRGame();
protected:
  void init();
};
#endif
