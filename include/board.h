#ifndef BOARD_H
#define BOARD_H

#include "common.h"

class Pole {
public:
  Pole();
  status_t drop(piece_t piece);
  int      getZ();
  piece_t* read(int z);
private:
  static const int _MAXZ = 6;

  int      _z;
  piece_t* _pieces;
};

class Board {
public:
  Board();
  status_t check();
  status_t drop(piece_t piece, int pole);
  int      fitness();
  int      getZ(int pole);
  piece_t* read(int pole, int z);
  void     reset();
private:
  Pole* _poles;
  bool _check_aux(piece_t* p1, piece_t* p2, piece_t* p3, piece_t* p4);
  int _recentMove;
  int _moves;
  static const int _NUMPOLES = 7;
};
#endif
