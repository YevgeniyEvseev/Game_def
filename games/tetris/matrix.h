#ifndef MATRIX_H
#define MATRIX_H

#include "tetris.h"

void clear_field(GameInfo_t *data);
void clear_figure(figure *fig);

void concat_matrix(GameInfo_t *data);
void copy_figure(figure *source, figure *dest);
int check_gameover(GameInfo_t *data);
void rotate_matrix(GameInfo_t *data);
void matrix_down_r(int matrix[][20], int row);

#endif