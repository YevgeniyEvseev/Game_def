#include <ncurses.h>

#include "../../define.h"
#include "tetris.h"

void tetris(const char* user_n) {
  //mvprintw(TOP_MENU + 20, LEFT_MENU + 20, "TETRIS");
  GameInfo_t data;
  init_game_info(&data);  
}

void tetris_consol(const char* user_n) {}