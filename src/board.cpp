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

bool Board::_check_aux(piece_t** file) {
  int and_check = 0xFF;
  int or_check  = 0x00;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++)
      if(!*(file + i + j)) return false;

    for(int j = 0; j < 4; j++) {
      and_check &= **(file + i + j);
      or_check  |= **(file + i + j);
    }

    if(((and_check & 0xF0) == (or_check & 0xF0)) || ((and_check & 0x0F) == (or_check & 0x0F))) return true;
  }

  return false;
}

status_t Board::check() {
  int r = _recentMove;
  int z = _poles[_recentMove].getZ() - 1;

  piece_t* column[7];
  piece_t* row[7];
  piece_t* diag1[7];
  piece_t* diag2[7];

  for(int i = -3; i <= 3; i++) {
    column[i + 3] = read(r, z + i);
    row[i + 3]    = read(r + i, z);
    diag1[i + 3]  = read(r + i, z + i);
    diag2[i + 3]  = read(r + i, z - i);
  }

  /* Check Down */
  if(_check_aux(column) || _check_aux(row) || _check_aux(diag1) || _check_aux(diag2)) return STATUS_VICTORY;

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
