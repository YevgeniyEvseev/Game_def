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
      new_food(&data->food);
      *state = SPAWN;
      break;
      /*
    case SPAWN:
      copy_figure(&data->new_figure, &data->cur_figure);
      spawn_new_figure(&data->new_figure);
      if (check_intersection(data) != 0) {
        *state = GAMEOVER;
        return;
      }
      print_info(&data->info);
      *state = STANDBY;
      controler_game(data, state, KEY_UP);
      break;
      /*
    case STANDBY:
      controler_game(data, state, input);
      break;
    case SHIFTING:
      ++data->cur_figure.y_offset;
      if (check_intersection(data) != 0) {
        --data->cur_figure.y_offset;
        *state = ATTACHING;
      } else {
        *state = STANDBY;
      }
      break;
    case ATTACHING:
      concat_matrix(data);
      check_full_row(data);

      *state = SPAWN;
      if (check_gameover(data)) *state = GAMEOVER;
      break;
      */
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
  data->body[0].y = 10;
  data->body[1].x = 6;
  data->body[1].y = 10;
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
