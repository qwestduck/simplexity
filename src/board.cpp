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

bool Board::_check_aux(piece_t* p1, piece_t* p2, piece_t* p3, piece_t* p4) {
  if(!p1 || !p2 || !p3 || !p4) return false;

  int and_check;
  int or_check;

  and_check = *p1 & *p1 & *p2 & *p3;
  or_check  = *p1 | *p1 | *p2 | *p3;

  return ((and_check & 0xF0) == (or_check & 0xF0)) || ((and_check & 0x0F) == (or_check & 0x0F));
}

status_t Board::check() {
  int z = _poles[_recentMove].getZ();

  /* Check for victory */
  piece_t* zd0 = read(_recentMove, z - 1);
  piece_t* zd1 = read(_recentMove, z - 2);
  piece_t* zd2 = read(_recentMove, z - 3);
  piece_t* zd3 = read(_recentMove, z - 4);

  /* Check Down */
  if(_check_aux(zd0, zd1, zd2, zd3)) return STATUS_VICTORY;

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

piece_t* Board::read(int pole, int z) {
  if(pole < 0 || pole > _NUMPOLES) return NULL;

  return _poles[pole].read(z);
}

void Board::reset() {

}
