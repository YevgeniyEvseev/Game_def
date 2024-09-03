#include <ncurses.h>

#include "../../../define.h"
#include "../tetris.h"
#include "define.h"

void render_field(const Snake_t *data) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int i_offset = data->cur_figure.x_offset + i + 1;
      int j_offset = data->cur_figure.y_offset + j;
      if (data->cur_figure.data[i][j] == 1)
        mvaddch(j_offset + BEGIN_Y, i_offset + BEGIN_X, ACS_BLOCK);
    }
  }

  refresh();
}

void render_figure(const figure *fig) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int i_offset = fig->x_offset + i;
      int j_offset = fig->y_offset + j;
      if (fig->data[i][j] == 1)
        mvaddch(j_offset + BEGIN_Y, i_offset + BEGIN_X, ACS_BLOCK);
      else
        mvaddch(j_offset + BEGIN_Y, i_offset + BEGIN_X, ' ');
    }
  }
  refresh();
}
