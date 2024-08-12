#ifndef DEFINES_H
#define DEFINES_H

#define TOP_MENU 2
#define LEFT_MENU 5

#define COUNT_MENU 7
#define KEY_ENTER_CLICK_ON 1
#define KEY_ENTER_CLICK_OFF 0

typedef enum {
  TETRIS_CONSOL,
  TETRIS,
  SNAKE_CONSOL,
  SNAKE,
  SEA_BATLE,
  TANKS,
  EXIT
} game_t;

void set_param_ncurses();
int select_game(const char* user_n, int* choice);
void render_menu(const char* user_n, int n_game);

void tetris(const char* user_n);
void sea_batle(const char* user_n);
void tanks(const char* user_n);
void snake(const char* user_n);
void tetris_consol(const char* user_n);
void snake_consol(const char* user_n);

#endif