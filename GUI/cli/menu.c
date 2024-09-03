#include <ncurses.h>

#include "../../define.h"

const char* menu_game[COUNT_MENU] = {
    "tetris consol", "tetris", "snake consol", "snake",
    "Sea batle",     "tanks",  "EXIT"};

void render_menu(const char* user_n, int n_game) {
  mvprintw(TOP_MENU, LEFT_MENU, "LEGENG GAME\n");
  for (int i = 0; i < COUNT_MENU; ++i) {
    if (n_game == i) {
      mvprintw(TOP_MENU + i + 1, LEFT_MENU, ">");
    } else {
      mvprintw(TOP_MENU + i + 1, LEFT_MENU, " ");
    }
    printw("%s\n", menu_game[i]);
  }
}
