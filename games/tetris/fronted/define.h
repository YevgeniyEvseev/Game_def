#ifndef DEFINE_FRONTED
#define DEFINE_FRONTED

#define BOARD 2
#define ROWS 20
#define COLS 10
#define BEGIN_X 4
#define END_X 13
#define BEGIN_Y 4
#define END_Y 23

#include "../tetris.h"

void draw_rectangle(int top, int bottom, int left, int right);
void render_field(const GameInfo_t *data);
void render_data(const GameInfo_t *data);
void print_info(const GameInfo_t *info);
void render_figure(const figure *fig);

#endif