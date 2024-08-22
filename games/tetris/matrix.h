#ifndef MATRIX_H
#define MATRIX_H

#include "tetris.h"

void clear_field(GameInfo_t *data);
void clear_figure(figure *fig);

void concat_matrix(GameInfo_t *data);
void copy_figure(figure *source, figure *dest);

#endif