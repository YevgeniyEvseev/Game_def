#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "define.h"

int main() {
  char user_n[256] = {0};
  int game_n = 0;
  int key_enter = KEY_ENTER_CLICK_OFF;
  printf("%s", "Enter name user\n");

  if (!scanf("%s", user_n)) {
    printf("Name is empty");
    return 1;
  }
  set_param_ncurses();
  while (!(game_n == EXIT && key_enter == KEY_ENTER_CLICK_ON)) {
    key_enter = select_game(user_n, &game_n);
    render_menu(user_n, game_n);
  }

  endwin();
  return EXIT_SUCCESS;
}

void set_param_ncurses() {
  srand(time(NULL));

  // initialize the library
  initscr();
  // set implicit modes
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  setlocale(LC_ALL, "");
  // invisible cursor, visibility of cursor (0,1,2)
  curs_set(FALSE);
  // getch() will be non-blocking
  nodelay(stdscr, TRUE);
}

int select_game(const char* user_n, int* choice) {
  int key = 0;
  switch (key = getch()) {
    case KEY_DOWN:
      if (*choice < COUNT_MENU - 1) (*choice)++;
      break;
    case KEY_UP:
      if (*choice > 0) (*choice)--;
      break;
    case 10:
      key = KEY_ENTER_CLICK_ON;
    default:
      break;
  }
  return key;
}