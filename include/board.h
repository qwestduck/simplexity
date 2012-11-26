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
  status_t drop(piece_t piece, int pole);
  int      fitness();
  int      getZ(int pole);
  piece_t* read(int pole, int z);
private:
  Pole* poles;
  static const int _NUMPOLES = 7;
};
#endif
