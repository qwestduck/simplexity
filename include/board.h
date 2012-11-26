#ifndef BOARD_H
#define BOARD_H

#define STATUS_OK 0
#define STATUS_POLEFULL 1

#define PIECE_WHITESQUARE 0x00
#define PIECE_WHITECIRCLE 0x01
#define PIECE_REDSQUARE   0x10
#define PIECE_REDCIRCLE   0x11

typedef int piece_t;
typedef int status_t;

class Pole {
public:
  Pole();
  status_t drop(piece_t piece);
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
  status_t drop(piece_t piece, int pole);
  int      fitness();
  int      getZ(int pole);
  piece_t* read(int pole, int z);
private:
  Pole* poles;
  static const int numPoles = 7;
};
#endif
