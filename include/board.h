#ifndef BOARD_H
#define BOARD_H

typedef piece_t int;
typedef status_t int;

class Pole {
public:
  Pole();
  status_t drop();
  int      getZ();
  piece_t* read(int z);
private:
  static const int maxZ = 6;

  int      _z;
  piece_t* _pieces;
};

class Board {
public:
  Board();
  status_t drop(int pole);
  int      fitness();
  int      getZ(int pole);
  piece_t* read(int pole, int z);
private:
  Pole* poles;
  static const int numPoles = 7;
};
#endif
