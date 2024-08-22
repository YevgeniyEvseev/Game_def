#include "../matrix.h"
#include "../tetris.h"

void clear_field(GameInfo_t *data) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      data->field[i][j] = 0;
    }
  }
}

void clear_figure(figure *fig) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      fig->data[i][j] = 0;
    }
  }
  fig->x_offset = 0;
  fig->y_offset = 0;
}

void concat_matrix(GameInfo_t *data) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int i_offset = data->cur_figure.x_offset + i;
      int j_offset = data->cur_figure.y_offset + j;
      if (data->cur_figure.data[i][j] == 1) {
        data->field[i_offset][j_offset] = data->cur_figure.data[i][j];
      }
    }
  }
}


void copy_figure(figure *source, figure *dest) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      dest->data[i][j] = source->data[i][j];
    }
  }
  dest->x_offset = 5;
  dest->y_offset = 0;
}