#include <ncurses.h>
#include <stdlib.h>

#include "../../../define.h"
#include "../fronted/define.h"
//#include "../matrix.h"
#include "../snake.h"

void init_game_info(GameInfo_t *data) {
  clear_field(data);
  data->high_score = 0;
  data->score = 0;
  data->pause = 0;
  data->level = 0;
  data->speed = 10;
}

