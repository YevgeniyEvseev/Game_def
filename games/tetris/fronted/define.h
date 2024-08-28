#ifndef DEFINE_FRONTED
#define DEFINE_FRONTED

#include "../tetris.h"

void draw_rectangle(int top, int bottom, int left, int right);
void render_field(const GameInfo_t *data);
void render_info(const GameInfo_t *data);
void print_info(const GameInfo_t *info);
void render_figure(const figure *fig);
void render_game_over();
void render_pause();

#endif