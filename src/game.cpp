#include "game.h"

Game::Game() {
  _board = new Board();
  _gameID = 0;
}

void Game::play() {
  for(; _gameID < _MAXGAMES; _gameID++) {
    bool gameOver = false;
    int player = _gameID % 2;

    while(!gameOver) {
      player ? _p2->move() : _p1->move();

      player = 1 - player;
    }

    gameOver = false;
    _board->reset();
  }
}

RvRGame::RvRGame() {
  init();
}

void RvRGame::init() {
  _p1 = new RandomPlayer(_board, PLAYER_RED);
  _p2 = new RandomPlayer(_board, PLAYER_WHITE);
}
