#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>

typedef int color_t;
typedef int piece_t;
typedef int player_t;
typedef int status_t;

#define INFINITY          65536

#define PLAYER_WHITE      0
#define PLAYER_RED        1

#define STATUS_OK         0
#define STATUS_POLEFULL   1
#define STATUS_POLEEMPTY  2
#define STATUS_BADPOLE    3
#define STATUS_VICTORY    1
#define STATUS_CAT        2

#define SHAPE_SQUARE      0
#define SHAPE_CIRCLE      1

#define ALPHABETA_DEPTH   4

#define VERBOSITY_PLAYBYPLAY false

/* MSB - PLAYER : LSB - SHAPE */
#define PIECE_WHITESQUARE 0x00
#define PIECE_WHITECIRCLE 0x01
#define PIECE_REDSQUARE   0x10
#define PIECE_REDCIRCLE   0x11
#endif
