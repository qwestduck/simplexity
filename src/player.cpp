#include "player.h"

Player::Player() {

}

Player::Player(Board* board, color_t color) {

}

RandomPlayer::RandomPlayer(Board* board, color_t color) {

}

status_t RandomPlayer::move() {
  return STATUS_OK;
}
