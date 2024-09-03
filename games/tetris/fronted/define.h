#ifndef DEFINE_FRONTED
#define DEFINE_FRONTED

#include "../tetris.h"


void render_field(const Tetris *data);
void render_info(Tetris *data);
void render_figure(const figure *fig);

#endif