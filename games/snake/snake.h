#ifndef SNAKE_H
#define SNAKE_H

#include "../../lib/lib_game.h"

enum intersection_t {
  NOT_ITR,
  FOOD,
  BODY,
  LEFT_BOARD,
  RIGHT_BOARD,
  UP_BOARD,
  DOWN_BOARD
};
enum direct { UP_WAY, RIGHT_WAY, DOWN_WAY, LEFT_WAY };

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
void render_figure_to_field(Snake_t *data);
void controler_game_snake(Snake_t *data, state_game *state, int input);
void move_snake(Snake_t *data);
void offset_matrix_snake(Snake_t *data, int x, int y);
int check_intersection_snake(Snake_t *data);
void grow_snake(Snake_t *data, Point *last_p);

#endif