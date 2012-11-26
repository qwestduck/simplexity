#include "game.h"

Game::Game() {
  _board = new Board();
}

void Game::play() {
  for(int i = 0; i < _MAXGAMES; i++) {
    bool gameOver = false;
    int player = i % 2;

    while(!gameOver) {
      player ? _p2->move() : _p1->move();

      switch(_board->check()) {
      case STATUS_VICTORY:
        std::cout << "Victory: Player " << player << std::endl;
        gameOver = true;
        break;
      case STATUS_CAT:
        gameOver = true;
        break;
      }

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
