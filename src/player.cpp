#include "player.h"
#include <ctime>
#include <cstdlib>

bool _seeded = false;

int Player::numPlayers = 0;

Player::Player() {
  _id = numPlayers;
  numPlayers++;
}

Player::Player(Board* board, color_t color) {

}

RandomPlayer::RandomPlayer(Board* board, color_t color) {
  if(!_seeded) {
    srand(time(NULL));
    _seeded = true;
  }
}

status_t RandomPlayer::move() {
  bool moved = false;

  while(!moved) {
    int pieceType = rand() % 2;
    int pole = rand() % 7;
    if(_board->drop((piece_t) (_id << 4) + pieceType, pole) == STATUS_OK)
      moved = true;
  }

  return STATUS_OK;
}
