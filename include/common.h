#ifndef COMMON_H
#define COMMON_H
typedef int color_t;
typedef int piece_t;
typedef int player_t;
typedef int status_t;

#define PLAYER_RED   0
#define PLAYER_WHITE 1

#define STATUS_OK    0
#define STATUS_POLEFULL 1

#define PIECE_WHITESQUARE 0x00
#define PIECE_WHITECIRCLE 0x01
#define PIECE_REDSQUARE   0x10
#define PIECE_REDCIRCLE   0x11
#endif
