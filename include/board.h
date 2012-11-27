#ifndef BOARD_H
#define BOARD_H

#include "common.h"

class Pole {
public:
  Pole();
  status_t drop(piece_t piece);
  status_t undrop();
  int      getZ();
  piece_t* read(int z);
  void     reset();
private:
  static const int _MAXZ = 6;

  int      _z;
  piece_t* _pieces;
};

class Board {
public:
  Board();
  status_t check();
  status_t drop(piece_t piece, int pole, bool dry = false);
  status_t undrop(int pole);
  int      fitness();
  int      getZ(int pole);
  int      getMoves();
  piece_t* read(int pole, int z);
  void     reset();
private:
  Pole* _poles;
  int _recentMove;
  int _moves;
  static const int _NUMPOLES = 7;
};
#endif
