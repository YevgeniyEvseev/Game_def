#include <ncurses.h>
#include <stdlib.h>

#include "../../../GUI/cli/interface_consol_game.h"
#include "../../../define.h"
#include "../fronted/define.h"
#include "../matrix.h"
#include "../tetris.h"

void init_game_info(Tetris *data) {
  clear_field(data->info.field);
  data->info.high_score = 0;
  data->info.score = 0;
  data->info.pause = 0;
  data->info.level = 0;
  data->info.speed = 10;
}

void updateCurrentState(Tetris *data, state_game *state, const char *user,
                        int input) {
  switch (*state) {
    case START:
      spawn_new_figure(&data->new_figure);
      //  render_info(data);
      *state = SPAWN;
      break;
    case SPAWN:
      copy_figure(&data->new_figure, &data->cur_figure);
      spawn_new_figure(&data->new_figure);
      if (check_intersection(data) != 0) {
        *state = GAMEOVER;
        return;
      }
      // render_info(data);
      *state = STANDBY;
      controler_game(data, state, KEY_UP);
      break;
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
    case PAUSE:
      // render_pause();
      *state = STANDBY;
      break;
    case GAMEOVER:
      // render_game_over();
      *state = EXIT_STATE;
      break;
    case EXIT_STATE:

      break;
    default:
      break;
  }
}

void spawn_new_figure(figure *fig) {
  clear_figure(fig);
  int value = rand() % 7;

  int figures[7][4] = {{1, 3, 5, 7}, {2, 4, 5, 7}, {3, 4, 5, 6}, {3, 4, 5, 7},
                       {2, 3, 5, 7}, {3, 5, 6, 7}, {2, 3, 4, 5}};
  for (int c = 0; c < 4; c++) {
    int x = figures[value][c] % 2;
    int y = figures[value][c] / 2;
    fig->data[x][y] = 1;
  }
  fig->x_offset = 15;
  fig->y_offset = 2;
}

void controler_game(Tetris *data, state_game *state, int input) {
  int old_offset_x = data->cur_figure.x_offset;
  int old_offset_y = data->cur_figure.y_offset;
  switch (userInput_consol(input)) {
    case TERMINATE:
      *state = GAMEOVER;
      break;
    case UP:
      --data->cur_figure.y_offset;
      // check under field
      if (data->cur_figure.y_offset == -1) {
        if (data->cur_figure.data[1][0] == 1) ++data->cur_figure.y_offset;
      }
      break;

    case DOWN:
      ++data->cur_figure.y_offset;
      if (check_intersection(data) > 0) {
        --data->cur_figure.y_offset;
        *state = ATTACHING;
      }
      break;

    case LEFT:
      --data->cur_figure.x_offset;
      if (check_intersection(data) > 0) ++data->cur_figure.x_offset;
      break;

    case RIGHT:
      ++data->cur_figure.x_offset;
      if (check_intersection(data) > 0) --data->cur_figure.x_offset;
      break;

    case ROTATE:
      rotate_matrix(data);
      break;

    case PAUSE_KEY:
      *state = PAUSE;
      break;

    default:
      break;
  }
}

int check_intersection(Tetris *data) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int d_i = data->cur_figure.x_offset + i;
      int d_j = data->cur_figure.y_offset + j;
      if (data->cur_figure.data[i][j] == 1) {
        if (d_i < 0) return LEFT_BOARD;
        if (d_i > 9) return RIGHT_BOARD;
        if (d_j > 19) return DOWN_BOARD;
        if (data->cur_figure.data[i][j] == data->info.field[d_i][d_j])
          return FIELD;
      }
    }
  }
  return NOT_ITR;
}

void check_full_row(Tetris *data) {
  int c_row = 0;
  for (int j = 20; j > 0; j--) {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
      if (data->info.field[i][j] == 1) sum++;
    }
    if (sum == 10) {
      matrix_down_r(data->info.field, j);
      c_row = 2 * c_row + 100;
      data->info.speed = 10 - data->info.score / 600;
      if (data->info.speed > 10) data->info.speed = 10;
      j++;
    }
  }
  data->info.score += c_row;
}