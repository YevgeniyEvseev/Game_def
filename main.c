#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "define.h"

int main() {
  printf("%s", "Enter name user\n");
  char user_n[256] = {0};
  if (!scanf("%s", user_n)) {
    printf("Name is empty");
    return 1;
  }

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

  render_menu(user_n);
  { /* code */

    // draw field and matrix game
    // render_game();
    // game_loop(user_n);

    /// refresh();
    //   nanosleep(&ts, NULL);  // provides simple effect

    // your code goes here
    getchar();

    // end curses
    endwin();
    return EXIT_SUCCESS;
  }

  int render_menu(const char *user_n) {
    int choice = 0;
    while (/* condition */) {
      mvprintw(TOP_MENU, LEFT_MENU, "LEGENG GAME\n");

      for (int i = 0; i < COUNT_MENU; ++i) {
        if (choice == i) }
      // getchar();
    }
  }