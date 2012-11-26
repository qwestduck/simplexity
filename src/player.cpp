#include "player.h"
#include <ctime>
#include <cstdlib>

bool _seeded = false;

Player::Player() {

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

  }

  return STATUS_OK;
}
