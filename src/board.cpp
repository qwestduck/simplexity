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

piece_t* Pole::read(int z) {
  if(z < 0 || z >= _z) return NULL;

  return &_pieces[z];
}

Board::Board() {
  _poles = new Pole[_NUMPOLES];
  _moves = 0;
}

status_t Board::check() {
  int and_check;
  int or_check;
  int z0;

  /* Check for victory */
  /* Check down */
  z0 = _poles[_recentMove].getZ();
  if(z0 >= 4) {
    piece_t zd0 = *_poles[_recentMove].read(z0-1);
    piece_t zd1 = *_poles[_recentMove].read(z0-2);
    piece_t zd2 = *_poles[_recentMove].read(z0-3);
    piece_t zd3 = *_poles[_recentMove].read(z0-4);

    and_check = zd0 & zd1 & zd2 & zd3;
    or_check  = zd0 | zd1 | zd2 | zd3;

    if(((and_check >> 4) == (or_check >> 4)) || ((and_check & 0x0F) == (or_check & 0x0F))) return STATUS_VICTORY;
  }
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
