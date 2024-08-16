#include "tetris.h"

#include <ncurses.h>

#include "../../define.h"

void tetris(const char* user_n) {
  // mvprintw(TOP_MENU + 20, LEFT_MENU + 20, "TETRIS");
  GameInfo_t data;
  init_game_info(&data);
  data.high_score = read_file();
}

void tetris_consol(const char* user_n) {}