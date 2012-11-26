#ifndef GAME_H
#define GAME_H

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
  Player* p1;
  Player* p2;
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
