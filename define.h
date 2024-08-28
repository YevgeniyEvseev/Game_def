#ifndef DEFINES_H
#define DEFINES_H

#define TOP_MENU 2
#define LEFT_MENU 5

#define COUNT_MENU 7
#define KEY_ENTER_CLICK_ON 1
#define KEY_ENTER_CLICK_OFF 0

#define BOARD 2
#define ROWS 20
#define COLS 10
#define BEGIN_X BOARD + 1
#define END_X BEGIN_X + COLS
#define BEGIN_Y BOARD + 1
#define END_Y ROWS + BEGIN_Y

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