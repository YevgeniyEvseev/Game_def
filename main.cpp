#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game_def_cpp.h"

extern "C" {
#include "define.h"
}

int main(int argc, char* argv[]) {
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
    void (*name_games[COUNT_MENU - 1])(const char*, int argc, char* argv[]) = {
        tetris_consol, tetris, snake_consol, snake, sea_batle, tanks};
    key_enter = select_game(user_n, &game_n);
    render_menu(user_n, game_n);
    if (key_enter == KEY_ENTER_CLICK_ON && game_n < 6) {
      name_games[game_n](user_n, argc, argv);
    }
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