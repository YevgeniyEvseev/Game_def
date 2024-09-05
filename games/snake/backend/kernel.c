#include <ncurses.h>
#include <stdlib.h>

#include "../../../define.h"
#include "../fronted/define.h"
// #include "../matrix.h"
#include "../../../GUI/cli/interface_consol_game.h"
#include "../snake.h"

void init_game_snake(Snake_t *data) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      mvaddch(j + BEGIN_Y, i + BEGIN_X + 1, ' ');
    }
  }
  data->info.high_score = 0;
  data->info.score = 0;
  data->info.pause = 0;
  data->info.level = 0;
  data->info.speed = 10;
}

void updateCurrentState_snake(Snake_t *data, state_game *state,
                              const char *user, int input) {
  switch (*state) {
    case START:
      new_snake(&data->cur_figure);
      data->food.x = 3;
      data->food.y = 5;
      *state = STANDBY;
      break;

    case SPAWN:
      render_figure_to_field(data);
      new_food(data);

      print_info(&data->info);
      *state = STANDBY;
      break;

    case STANDBY:
      controler_game_snake(data, state, input);
      break;

    case SHIFTING:
      int event = 0;
      move_snake(data);
      if ((event = check_intersection_snake(data)) == FOOD) {
        *state = ATTACHING;
      } else if (event == NOT_ITR) {
        *state = STANDBY;
      } else {
        *state = GAMEOVER;
      }
      break;

    case ATTACHING:
      grow_snake(data);
      data->info.score += 100;
      *state = SPAWN;
      break;

    case PAUSE:
      render_pause();
      *state = STANDBY;
      break;
    case GAMEOVER:
      render_game_over();
      *state = EXIT_STATE;
      break;
    case EXIT_STATE:

      break;
    default:
      break;
  }
}

void new_snake(figure *data) {
  data->count = 2;
  data->direction = LEFT_WAY;
  data->body[0].x = 5;
  data->body[0].y = 5;
  data->body[1].x = 6;
  data->body[1].y = 5;
}

void new_food(Snake_t *data) {
  int x = rand() % 10;
  int y = rand() % 20;
  int x_tmp = x;
  int y_tmp = y;
  while (y >= 0) {
    if (data->info.field[x][y] == 0) {
      data->food.x = x;
      data->food.y = y;
      return;
    }
    if (x == 0) {
      y--;
      x = 9;
    } else
      x--;
  }
  x = x_tmp;
  y = y_tmp;
  while (y < 20) {
    if (data->info.field[x][y] == 0) {
      data->food.x = x;
      data->food.y = y;
      return;
    }
    if (x == 9) {
      y++;
      x = 0;
    } else
      x++;
  }
}

void render_figure_to_field(Snake_t *data) {
  clear_field(data->info.field);
  for (int i = 0; i < data->cur_figure.count; ++i) {
    int i_field = data->cur_figure.body[i].x;
    int j_field = data->cur_figure.body[i].y;
    data->info.field[i_field][j_field] = 1;
  }
}

void controler_game_snake(Snake_t *data, state_game *state, int input) {
  switch (userInput(input)) {
    case TERMINATE:
      *state = GAMEOVER;
      break;
    case UP:
      if (data->cur_figure.direction != UP_WAY &&
          data->cur_figure.direction != DOWN_WAY) {
        data->cur_figure.direction = UP_WAY;
      }
      break;

    case DOWN:
      if (data->cur_figure.direction != UP_WAY &&
          data->cur_figure.direction != DOWN_WAY) {
        data->cur_figure.direction = DOWN_WAY;
      }
      break;

    case LEFT:
      if (data->cur_figure.direction != LEFT_WAY &&
          data->cur_figure.direction != RIGHT_WAY) {
        data->cur_figure.direction = LEFT_WAY;
      }
      break;

    case RIGHT:
      if (data->cur_figure.direction != LEFT_WAY &&
          data->cur_figure.direction != RIGHT_WAY) {
        data->cur_figure.direction = RIGHT_WAY;
      }
      break;

    case ROTATE:
      *state = SHIFTING;
      break;

    case PAUSE_KEY:
      *state = PAUSE;
      break;

    default:
      break;
  }
}

void offset_matrix_snake(Snake_t *data, int x, int y) {
  for (int i = data->cur_figure.count - 1; i > 0; i--) {
    data->cur_figure.body[i].x = data->cur_figure.body[i - 1].x;
    data->cur_figure.body[i].y = data->cur_figure.body[i - 1].y;
  }
  data->cur_figure.body[0].x += x;
  data->cur_figure.body[0].y += y;
}

void move_snake(Snake_t *data) {
  int x = 0, y = 0;
  switch (data->cur_figure.direction) {
    case UP_WAY:
      y--;
      break;
    case DOWN_WAY:
      y++;
      break;
    case LEFT_WAY:
      x--;
      break;
    case RIGHT_WAY:
      x++;
      break;
    default:
      break;
  }
  offset_matrix_snake(data, x, y);
}

int check_intersection_snake(Snake_t *data) {
  if (data->cur_figure.body[0].x < 0) return LEFT_BOARD;
  if (data->cur_figure.body[0].x > 9) return RIGHT_BOARD;
  if (data->cur_figure.body[0].y > 19) return DOWN_BOARD;
  if (data->cur_figure.body[0].y < 0) return UP_BOARD;

  if (data->cur_figure.body[0].x == data->food.x &&
      data->cur_figure.body[0].y == data->food.y)
    return FOOD;
  for (int i = 2; i < data->cur_figure.count; ++i) {
    if (data->cur_figure.body[0].x == data->cur_figure.body[i].x &&
        data->cur_figure.body[0].y == data->cur_figure.body[i].y)
      return BODY;
  }

  return NOT_ITR;
}

void grow_snake(Snake_t *data) {
  Point tmp;
  int lenght = data->cur_figure.count;
  tmp.x = data->cur_figure.body[lenght - 1].x;
  tmp.y = data->cur_figure.body[lenght - 1].y;
  move_snake(data);
  data->cur_figure.count++;
  data->cur_figure.body[lenght].x = tmp.x;
  data->cur_figure.body[lenght].y = tmp.y;
}