#include "game.h"

Game::Game() {

}

void Game::play() {

}

RvRGame::RvRGame() {
  _board = new Board();
}

void RvRGame::init() {
  _p1 = new RandomPlayer(_board, PLAYER_RED);
  _p2 = new RandomPlayer(_board, PLAYER_WHITE);
}
