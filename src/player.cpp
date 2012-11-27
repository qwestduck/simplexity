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

  _board = board;
  _color = color;
}

status_t RandomPlayer::move() {
  bool moved = false;

  while(!moved) {
    int pieceType = rand() % 2;
    int pole = rand() % 7;
    piece_t piece = (piece_t) (_id << 4) + pieceType;
    if(_board->drop(piece, pole) == STATUS_OK) {
      if(VERBOSITY_PLAYBYPLAY) {
        std::cout << "RandomPlayer::move 0x";
        std::cout << std::setw(2) << std::setfill('0') << std::hex << piece;
        std::cout << "->" << pole << std::endl;
      }

      moved = true;
    }
  }

  return STATUS_OK;
}

SmartPlayer::SmartPlayer(Board* board, color_t color) {
  _board = board;
  _color = color;
}

status_t SmartPlayer::move() {
  alphabeta(_board, ALPHABETA_DEPTH, -INFINITY, INFINITY, true);

  return STATUS_OK;
}

int SmartPlayer::alphabeta(Board* board, int depth, int a, int B, bool isMax) {
  if(depth == 0/* || node is a terminal node*/)
    return /*the heuristic value of node*/ 0;
  if(isMax) {
    for(int i = 0; i < 7; i++) {
      for(int pieceType = 0; pieceType < 2; pieceType++) {
        if(_board->drop((piece_t) (_id << 4) + pieceType, i, true) != STATUS_OK) continue;
        a = std::max(a, alphabeta(_board, depth - 1, a, B, !isMax));
        _board->undrop(i);
        if(B <= a) return a;
      }
    }

    return a;
  } else {
    for(int i = 0; i < 7; i++) {
      for(int pieceType = 0; pieceType < 2; pieceType++) {
        if(_board->drop((piece_t) (_id << 4) + pieceType, i, true) != STATUS_OK) continue;
        B = std::min(B, alphabeta(_board, depth - 1, a, B, !isMax));
        _board->undrop(i);
        if(B <= a) return B;
      }
    }

    return B;
  }
}

