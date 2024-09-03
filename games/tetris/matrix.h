#ifndef MATRIX_H
#define MATRIX_H

#include "tetris.h"


void clear_figure(figure *fig);

void concat_matrix(Tetris *data);
void copy_figure(figure *source, figure *dest);
int check_gameover(Tetris *data);
void rotate_matrix(Tetris *data);
void matrix_down_r(int matrix[][20], int row);

#endif