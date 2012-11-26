#include "board.h"

status_t Pole::drop(piece_t piece) {
  return STATUS_OK;
}

Board::Board() {

}

status_t Board::drop(piece_t piece, int pole) {
  return poles[pole].drop(piece);
}
