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
      spawn_new_figure(&(data->new_figure));
      render_data(data);
      *state = SPAWN;
      break;
    case SPAWN:
      /* code */
      break;

    case MOVING:
      /* code */
      break;
    case SHIFTING:
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
  else if (action == KEY_END)
    rc = TERMINATE;
  else if (action == KEY_HOME)
    rc = PAUSE_KEY;
  return rc;
}

void spawn_new_figure(figure *fig) {
  int value = rand() % 7;

  int figures[7][4] = {{1, 3, 5, 7}, {2, 4, 5, 7}, {3, 4, 5, 6}, {3, 4, 5, 7},
                       {2, 3, 5, 7}, {3, 5, 6, 7}, {2, 3, 4, 5}};
  for (int c = 0; c < 4; c++) {
    int x = figures[value][c] % 2 + 4;
    int y = figures[value][c] / 2;
    fig->data[x][y] = 1;
  }
  fig->x_offset = 0;
  fig->y_offset = 3;
  // if (value != 0) move_up_matrix(matrix);
}