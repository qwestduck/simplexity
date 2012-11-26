#ifndef GAME_H
#define GAME_H

typedef player_t int;

class Game {
public:
  Game();
  void play();
  player_t winner();
  int moves();
protected:
  virtual void init() = 0;
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
