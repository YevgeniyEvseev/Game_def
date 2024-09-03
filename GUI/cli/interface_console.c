#include <ncurses.h>

#include "../../define.h"
#include "interface_consol_game.h"

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

void print_info(GameInfo_t *info) {
  mvprintw(BOARD + 14, 18, "%d", info->high_score);  // high

  mvprintw(BOARD + 11, 18, "%d", info->score);  // score

  mvprintw(BOARD + 16, 18, "%d", 10 - info->speed);  // speed

  mvprintw(BOARD + 18, 18, "%d", 10 - info->speed);  // level
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

UserAction_t userInput(int action) {
  UserAction_t rc = NOSIG;

  if (action == KEY_UP)
    rc = UP;
  else if (action == KEY_DOWN)
    rc = DOWN;
  else if (action == KEY_LEFT)
    rc = LEFT;
  else if (action == KEY_RIGHT)
    rc = RIGHT;
  else if (action == ' ')
    rc = ROTATE;
  else if (action == KEY_ENTER)
    rc = START_KEY;
  else if (action == 'q' || action == 'Q')
    rc = TERMINATE;
  else if (action == KEY_HOME)
    rc = PAUSE_KEY;
  return rc;
}

void clear_field(int data[][20]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      data[i][j] = 0;
    }
  }
}