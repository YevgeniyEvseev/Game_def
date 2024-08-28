#include "../matrix.h"
#include "../tetris.h"

void clear_field(GameInfo_t *data) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      data->field[i][j] = 0;
    }
  }
}

void clear_matrix(int matrix_tmp[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_tmp[i][j] = 0;
    }
  }
}

void clear_figure(figure *fig) {
  clear_matrix(fig->data);
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

void copy_matrix(int source[][4], int dest[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      dest[i][j] = source[i][j];
    }
  }
}

void copy_figure(figure *source, figure *dest) {
  copy_matrix(source->data, dest->data);
  dest->x_offset = 5;
  dest->y_offset = 0;
}

int check_gameover(GameInfo_t *data) {
  for (int i = 0; i < 10; ++i) {
    if (data->field[i][0] == 1) return 1;
  }
  return 0;
}

void rotate_matrix(GameInfo_t *data) {
  int x_c = 1, y_c = 2;
  int matrix_tmp[4][4];

  clear_matrix(matrix_tmp);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (data->cur_figure.data[i][j] == 1) {
        int i_new = x_c + (-1) * (y_c - j);
        int j_new = y_c + x_c - i;
        if (i_new > 3) i_new = 0;
        if (j_new > 3) j_new = 0;
        if (i_new < 0) i_new = 3;
        if (j_new < 0) j_new = 3;
        matrix_tmp[i_new][j_new] = 1;
      }
    }
  }

  clear_matrix(data->cur_figure.data);
  copy_matrix(matrix_tmp, data->cur_figure.data);
  while (check_intersection(data) == LEFT_BOARD) ++data->cur_figure.x_offset;
  while (check_intersection(data) == RIGHT_BOARD) --data->cur_figure.x_offset;
}

void matrix_down_r(int matrix[][20], int row) {
  for (int j = row; j > 1; j--) {
    for (int i = 0; i < 10; i++) {
      matrix[i][j] = matrix[i][j - 1];
    }
  }
}