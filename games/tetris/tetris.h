#ifndef TETRIS_H
#define TETRIS_H

#include "../../lib/lib_game.h"

typedef struct {
  int x_offset;
  int y_offset;
  int data[4][4];
} figure;

typedef struct {
  figure cur_figure;
  figure new_figure;
  GameInfo_t info;
} Tetris;

enum intersection { NOT_ITR, LEFT_BOARD, RIGHT_BOARD, DOWN_BOARD, FIELD };

void init_game_info(Tetris *data);

void updateCurrentState(Tetris *data, state_game *state, const char *user,
                        int input);

void spawn_new_figure(figure *fig);
void controler_game(Tetris *data, state_game *state, int input);
int check_intersection(Tetris *data);
void check_full_row(Tetris *data);
#endif