#include <ncurses.h>
#include <stdlib.h>

#include "../../../define.h"
#include "../fronted/define.h"
#include "../matrix.h"
#include "../tetris.h"

void init_game_info(GameInfo_t *data) {
  clear_field(data);
  data->high_score = 0;
  data->score = 0;
  data->pause = 0;
  data->level = 0;
  data->speed = 100;
  data->pause = 0;
}

void updateCurrentState(GameInfo_t *data, state_game *state, const char *user,
                        int input) {
  switch (*state) {
    case START:
      spawn_new_figure(&data->new_figure);
      render_info(data);
      *state = SPAWN;
      break;
    case SPAWN:
      copy_figure(&data->new_figure, &data->cur_figure);
      spawn_new_figure(&data->new_figure);
      render_info(data);
      *state = STANDBY;
      break;
    case STANDBY:
      controler_game(data, state, input);
      break;
    case SHIFTING:
      *state = STANDBY;
      /* code */
      break;
    case ATTACHING:
      /* code */
      break;
    case PAUSE:
      /* code */
      break;
    case GAMEOVER:
      /* code */
      break;
    case EXIT_STATE:
      /* code */
      break;
    default:
      break;
  }
}

UserAction_t userInput(int action) {
  UserAction_t rc = NOSIG;

  if (action == KEY_UP)
    rc = UP;
  else if (action == KEY_DOWN)
    rc = DOWN;
  else if (action == KEY_LEFT)
    rc = LEFT;
  else if (action == KEY_RIGHT)
    rc = RIGHT;
  else if (action == ' ')
    rc = ROTATE;
  else if (action == KEY_ENTER)
    rc = START_KEY;
  else if (action == 'q' || action == 'Q')
    rc = TERMINATE;
  else if (action == KEY_HOME)
    rc = PAUSE_KEY;
  return rc;
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
  // if (value != 0) move_up_matrix(matrix);
}

void controler_game(GameInfo_t *data, state_game *state, int input) {
  int old_offset_x = data->cur_figure.x_offset;
  int old_offset_y = data->cur_figure.y_offset;
  switch (userInput(input)) {
    case TERMINATE:
      *state = GAMEOVER;
      break;
    case UP:
      --data->cur_figure.y_offset;
      if (check_intersection(data) == TRUE) ++data->cur_figure.y_offset;
      break;

    case DOWN:
      ++data->cur_figure.y_offset;
      if (check_intersection(data) == TRUE) --data->cur_figure.y_offset;
      break;

    case LEFT:
      --data->cur_figure.x_offset;
      if (check_intersection(data) == TRUE) ++data->cur_figure.x_offset;
      break;

    case RIGHT:
      ++data->cur_figure.x_offset;
      if (check_intersection(data) == TRUE) --data->cur_figure.x_offset;
      break;

    default:
      break;
  }
}

int check_intersection(GameInfo_t *data) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int d_i = data->cur_figure.x_offset + i;
      int d_j = data->cur_figure.y_offset + j;
      if (data->cur_figure.data[i][j] == 1) {
        if (d_i < 0 || d_i > 9) return TRUE;
        if (d_j < 0 || d_j > 19) return TRUE;
        if (data->cur_figure.data[i][j] == data->field[d_i][d_j]) return TRUE;
      }
    }
  }
  return FALSE;
}