#include <ncurses.h>

#include "../../../define.h"
#include "../tetris.h"
#include "define.h"

void load_interface() {
  clear();
  draw_rectangle(BOARD, BOARD + ROWS + 1, BOARD + 1, BOARD + COLS + 2);
  draw_rectangle(BOARD, BOARD + 8, 17, 23);
  mvprintw(4, 18, "NEXT");
  draw_rectangle(BOARD + 9, BOARD + ROWS + 1, 17, 23);
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
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      if (data->field[i][j] == 1)
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

void render_info(const GameInfo_t *data) {
  render_figure(&data->new_figure);
  print_info(data);
}

void print_info(const GameInfo_t *info) {
  mvprintw(BOARD + 14, 18, "%d", info->high_score);  // high

  mvprintw(BOARD + 11, 18, "%d", info->score);  // score

  mvprintw(BOARD + 16, 18, "%d", 10 - info->speed);  // speed

  mvprintw(BOARD + 18, 18, "%d", info->speed);  // level
}

void render_game_over() {
  clear();
  mvprintw(BOARD + 10, 3, "                ");
  mvprintw(BOARD + 11, 3, "   GAME OVER    ");
  mvprintw(BOARD + 12, 3, "  -----------   ");
  refresh();
  nodelay(stdscr, FALSE);
  getch();
  nodelay(stdscr, TRUE);
}

void render_pause() {
  mvprintw(BOARD + 8, 5, "Pause");
  nodelay(stdscr, FALSE);
  getch();
  nodelay(stdscr, TRUE);
  mvprintw(BOARD + 8, 5, "     ");
}
