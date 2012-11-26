#include "game.h"

Game::Game() {

}

void Game::play() {
  bool gameOver = false;
  int player = 0;

  while(!gameOver) {
    player ? _p2->move() : _p1->move();

    player = 1 - player;
  }
}

RvRGame::RvRGame() {
  _board = new Board();
}

void RvRGame::init() {
  _p1 = new RandomPlayer(_board, PLAYER_RED);
  _p2 = new RandomPlayer(_board, PLAYER_WHITE);
}
