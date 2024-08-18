#include <ncurses.h>

#include "../../../define.h"
#include "../tetris.h"
#include "define.h"

void load_interface() {
  clear();
  draw_rectangle(BOARD + 1, BOARD + ROWS + 1, BOARD + 1, BOARD + COLS + 2);
  draw_rectangle(BOARD + 1, BOARD + 8, 17, 23);
  mvprintw(4, 18, "NEXT");
  draw_rectangle(BOARD + 9, BOARD + 20, 17, 23);
  mvprintw(BOARD + 10, 18, "SCORE");

  mvprintw(BOARD + 12, 18, "HIGH");
  mvprintw(BOARD + 13, 18, "SCORE");

  mvprintw(BOARD + 15, 18, "SPEED");

  mvprintw(BOARD + 17, 18, "LEVEL");
  refresh();
}

void draw_rectangle(int top, int bottom, int left, int right) {
  mvaddch(top, left, ACS_ULCORNER);
  for (int i = left + 1; i < right; i++) {
    mvaddch(top, i, ACS_HLINE);
  }
  mvaddch(top, right, ACS_URCORNER);
  for (int i = top + 1; i < bottom; i++) {
    mvaddch(i, right, ACS_VLINE);
  }
  mvaddch(bottom, left, ACS_LLCORNER);
  for (int i = left + 1; i < right; i++) {
    mvaddch(bottom, i, ACS_HLINE);
  }
  mvaddch(bottom, right, ACS_LRCORNER);
  for (int i = top + 1; i < bottom; i++) {
    mvaddch(i, left, ACS_VLINE);
  }
}

void render_field(const GameInfo_t *data) {
  int matrix_draw[10][20] = {0};
  clear_matrix(matrix_draw);
  add_matrix(matrix_draw, data->field, data->figure_m);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      if (matrix_draw[i][j] == 1)
        mvaddch(j + BEGIN_Y, i + BEGIN_X, ACS_BLOCK);
      else
        mvaddch(j + BEGIN_Y, i + BEGIN_X, ' ');
      refresh();
    }
  }
  render_game();
}