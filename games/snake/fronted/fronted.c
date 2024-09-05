#include <ncurses.h>

#include "../../../define.h"
#include "../snake.h"
#include "define.h"

void render_game_snake(const Snake_t *data) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      mvaddch(j + BEGIN_Y, i + BEGIN_X + 1, ' ');
    }
  }

  for (int i = 0; i < data->cur_figure.count; ++i) {
    mvaddch(data->cur_figure.body[i].y + BEGIN_Y,
            data->cur_figure.body[i].x + BEGIN_X + 1, ACS_BLOCK);
  }
  mvaddch(data->food.y + BEGIN_Y, data->food.x + BEGIN_X + 1, ACS_BLOCK);

  refresh();
}
