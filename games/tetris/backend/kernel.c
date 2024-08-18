#include <ncurses.h>

#include "../../../define.h"
#include "../tetris.h"

void init_game_info(GameInfo_t *data) {
  clear_matrix(data->field);
  clear_matrix(data->figure_m);
  data->high_score = 0;
  data->score = 0;
  data->pause = 0;
  data->level = 0;
  data->speed = 100;
  data->pause = 0;
}

void updateCurrentState(GameInfo_t *data, state_game *state, char *user,
                        int input) {}