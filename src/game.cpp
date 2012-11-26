#include "game.h"

Game::Game() {
  _board = new Board();
}

void Game::play() {
  int cats = 0;
  int wins[2];
  wins[0] = 0;
  wins[1] = 0;

  for(int i = 0; i < _MAXGAMES; i++) {
    bool gameOver = false;
    int player = i % 2;

    while(!gameOver) {
      player ? _p2->move() : _p1->move();

      switch(_board->check()) {
      case STATUS_VICTORY:
        std::cout << "Victory: Player " << player << ", Moves: " << _board->getMoves() << std::endl;
        wins[player]++;
        gameOver = true;
        break;
      case STATUS_CAT:
        std::cout << "CAT, Moves: " << _board->getMoves() << std::endl;
        cats++;
        gameOver = true;
        break;
      }

      player = 1 - player;
    }

    gameOver = false;
    _board->reset();
  }

  std::cout << "Player 0: " << wins[0] << ", Player 1: " << wins[1] << ", CATS: " << cats << std::endl;
  if(wins[0] > wins[1]) {
    std::cout << "Player 0 won more games" << std::endl;
  }

  if(wins[0] < wins[1]) {
    std::cout << "Player 1 won more games" << std::endl;
  }

  if(wins[0] == wins[1]) {
    std::cout << "The players won the same number of games" << std::endl;
  }
}

RvRGame::RvRGame() {
  init();
}

void RvRGame::init() {
  _p1 = new RandomPlayer(_board, PLAYER_RED);
  _p2 = new RandomPlayer(_board, PLAYER_WHITE);
}
