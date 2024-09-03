#ifndef INTERFACE_CONSOL_GAME_H
#define INTERFACE_CONSOL_GAME_H

#include "../../lib/lib_game.h"

void load_interface();
void clear_field(int data[][20]);
void draw_rectangle(int top, int bottom, int left, int right);
void print_info(GameInfo_t *info);
void render_game_over();
void render_pause();
UserAction_t userInput(int action);

#endif