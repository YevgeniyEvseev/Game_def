#ifndef DEFINE_FRONTED
#define DEFINE_FRONTED

#define BOARD 2
#define ROWS 20
#define COLS 10
#define BEGIN_X BOARD + 1
#define END_X BEGIN_X + COLS
#define BEGIN_Y BOARD + 1
#define END_Y ROWS + BEGIN_Y

#include "../tetris.h"

void draw_rectangle(int top, int bottom, int left, int right);
void render_field(const GameInfo_t *data);
void render_info(const GameInfo_t *data);
void print_info(const GameInfo_t *info);
void render_figure(const figure *fig);
void render_game_over();

#endif