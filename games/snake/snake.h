#ifndef SNAKE_H
#define SNAKE_H

#include "../../lib/lib_game.h"

enum intersection { NOT_ITR, LEFT_BOARD, RIGHT_BOARD, DOWN_BOARD, FIELD };
enum direct { TOP_WAY, RIGHT_WAY, DOWN_WAY, LEFT_WAY };

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int count;
  int direction;
  Point body[200];
} figure;

typedef struct {
  Point food;
  figure cur_figure;
  GameInfo_t info;
} Snake_t;

void init_game_snake(Snake_t *data);

void load_interface();
void updateCurrentState_snake(Snake_t *data, state_game *state,
                              const char *user, int input);
void new_snake(figure *data);
void new_food(Snake_t *food);

#endif