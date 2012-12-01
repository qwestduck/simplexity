#include "player.h"
#include <ctime>
#include <cstdlib>
#include <vector>

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
        std::cout << "RandomPlayer: " << (pieceType == 0 ? "Square" : "Circle") << " on pole " << pole << std::endl;
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
  int best_moves[14];
  piece_t best_piece[14];
  int array_size = 0;
  int piece;
  int a = -INFINITY;
  int ab = a;
  int m;
  int B = INFINITY;
  bool isMax = true;
  int depth = ALPHABETA_DEPTH;

  /* Unroll the first level of alphabeta */
  for(int i = 0; i < 7; i++) {
    for(int pieceType = 0; pieceType < 2; pieceType++) {
      piece = (piece_t) (_id << 4) + pieceType;
      if(_board->drop(piece, i) != STATUS_OK) continue;
      ab = alphabeta(_board, depth - 1, a, B, !isMax);
      if(ab > a) {
        array_size = 0;
      }
      if(ab >= a || (ab < a && array_size == 0)) {
        best_moves[array_size] = i;
        best_piece[array_size] = piece;
        array_size++;
      }
//      std::cout << "a = " << a << " : ab = " << ab << std::endl;
      a = std::max(a, ab);
      _board->undrop(i);
    }
  }

  if(array_size == 0) return STATUS_OK;

  if(VERBOSITY_PLAYBYPLAY)
    std::cout << "Smart player: " << _board->getMoves() << " " << ((best_piece[0] == 0) ? "Square" : "Circle") << " on pole " << best_moves[0] << " of " << array_size << " options" << std::endl;
  _board->drop(best_piece[0], best_moves[0]);

  return STATUS_OK;
}

int SmartPlayer::alphabeta(Board* board, int depth, int a, int B, bool isMax) {
  status_t game_status = _board->check();
  if(game_status == STATUS_VICTORY) {
    //return INFINITY;
    return isMax ? INFINITY : -INFINITY;
  }
  if(game_status == STATUS_CAT)
    return -1;
  if(depth == 0)
    return 0;
  if(isMax) {
    for(int i = 0; i < 7; i++) {
      for(int pieceType = 0; pieceType < 2; pieceType++) {
        if(_board->drop((piece_t) (_id << 4) + pieceType, i) != STATUS_OK) continue;
        a = std::max(a, alphabeta(_board, depth - 1, a, B, !isMax));
        _board->undrop(i);
        if(B <= a) return a;
      }
    }

    return a;
  } else {
    for(int i = 0; i < 7; i++) {
      for(int pieceType = 0; pieceType < 2; pieceType++) {
        if(_board->drop((piece_t) ((1-_id) << 4) + pieceType, i) != STATUS_OK) continue;
        B = std::min(B, alphabeta(_board, depth - 1, a, B, !isMax));
        _board->undrop(i);
        if(B <= a) return B;
      }
    }

    return B;
  }
}

