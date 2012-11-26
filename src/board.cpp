#include "board.h"

Pole::Pole() {
  _pieces = new piece_t[_MAXZ];
  _z = 0;
}

status_t Pole::drop(piece_t piece) {
  if(_z == _MAXZ) return STATUS_POLEFULL;

  _pieces[_z] = piece;
  _z++;

  return STATUS_OK;
}

Board::Board() {

}

status_t Board::drop(piece_t piece, int pole) {
  return poles[pole].drop(piece);
}
