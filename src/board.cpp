#include "board.h"

Pole::Pole() {
  _pieces = new piece_t[_MAXZ];
  _z = 0;
}

int Pole::getZ() {
  return _z;
}

status_t Pole::drop(piece_t piece) {
  if(_z == _MAXZ) return STATUS_POLEFULL;

  _pieces[_z] = piece;
  _z++;

  return STATUS_OK;
}

Board::Board() {
  _poles = new Pole[_NUMPOLES];
  _moves = 0;
}

status_t Board::check() {
  /* Check for victory */

  /* Check for cat */
  if(_moves == 6 * _NUMPOLES) return STATUS_CAT;

  return STATUS_OK;
}

status_t Board::drop(piece_t piece, int pole) {
  if(pole < 0 || pole >= _NUMPOLES) return STATUS_BADPOLE;

  status_t ret = _poles[pole].drop(piece);

  if(ret == STATUS_OK) {
    _recentMove = pole;
    _moves++;
  }

  return ret;
}

void Board::reset() {

}
