#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "common.h"
#include "player.h"

class Game {
public:
  Game();
  void play();
  player_t winner();
  int moves();
protected:
  static const int _MAXGAMES = 20;

  virtual void init() = 0;
  Board* _board;
  Player* _p1;
  Player* _p2;
  player_t _winner;
  int _gameID;
  int _moves;
};

class RvRGame : public Game {
public:
  RvRGame();
private:
  void init();
};
#endif
