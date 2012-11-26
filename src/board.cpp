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

void Pole::reset() {
  _z = 0;
}

Board::Board() {
  _poles = new Pole[_NUMPOLES];
  _moves = 0;
}

status_t Board::check() {
  int r = _recentMove;
  int z = _poles[_recentMove].getZ() - 1;

  int* file[4];
  int color_counter[4];
  int shape_counter[4];
  int prev_color[4];
  int prev_shape[4];

  for(int i = 0; i < 7; i++) {
    file[0] = read(r + i - 3, z);
    file[1] = read(r, z + i - 3);
    file[2] = read(r + i - 3, z + i - 3);
    file[3] = read(r + i - 3, z - i + 3);

    for(int j = 0; j < 4; j++) {
      /* Initialize the first time through */
      if(i == 0) {
        color_counter[j] = 0;
        shape_counter[j] = 0;
        prev_color[j] = 0xC0;
        prev_shape[j] = 0x0C;
      }

      /* Trap Null references */
      if(!file[j]) {
        color_counter[j] = 0;
        shape_counter[j] = 0;
        prev_shape[j]    = 0x0C;
        prev_color[j]    = 0xC0;
      } else {
        if((*file[j] & 0xF0) == prev_color[j])
          color_counter[j]++;
        else
          color_counter[j] = 1;

        prev_color[j] = *file[j] & 0xF0;

        if((*file[j] & 0x0F) == prev_shape[j])
          shape_counter[j]++;
        else
          shape_counter[j] = 1;

        prev_shape[j] = *file[j] & 0x0F;
      }

      if(shape_counter[j] == 4 || color_counter[j] == 4) return STATUS_VICTORY;
    }
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

piece_t* Board::read(int pole, int z) {
  if(pole < 0 || pole > _NUMPOLES) return NULL;

  return _poles[pole].read(z);
}

void Board::reset() {
  _moves = 0;

  for(int i = 0; i < _NUMPOLES; i++)
    _poles[i].reset();
}
