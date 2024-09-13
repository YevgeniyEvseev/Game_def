#include <ncurses.h>

#include "../../../GUI/cli/interface_consol_game.h"
#include "../../../define.h"
#include "../tetris.h"
#include "define.h"

void render_field(const Tetris *data) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      if (data->info.field[i][j] == 1)
        mvaddch(j + BEGIN_Y, i + BEGIN_X + 1, ACS_BLOCK);
      else
        mvaddch(j + BEGIN_Y, i + BEGIN_X + 1, ' ');
    }
  }
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

void render_info(Tetris *data) {
  render_figure(&data->new_figure);
  print_info(&data->info);
}

