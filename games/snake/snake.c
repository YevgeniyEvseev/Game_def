#include "snake.h"

#include <ncurses.h>
#include <time.h>

#include "../../define.h"
#include "fronted/define.h"

void snake(const char* user_n) {}

void snake_consol(const char* user_n) {
  int flag_play = TRUE;
  Snake_t data;
  char* path = "games/snake/user_data.txt";
  int offset_char_in_file = 0, i = 0;
  state_game state = START;
  struct timespec ts = {
      .tv_sec = 0,                         // nr of secs
      .tv_nsec = 0.001 * 10 * 1000000000L  // nr of nanosecs
  };
  init_game_snake(&data);
  data.info.high_score = read_file(user_n, path, &offset_char_in_file);
  data.info.score = 0;
  load_interface();
  while (flag_play) {
    int input = getch();
    updateCurrentState_snake(&data, &state, user_n, input);

    if (state == EXIT_STATE) {
      flag_play = false;
      save_file(&data.info, path, user_n, data.info.score, offset_char_in_file);
    }

    if (data.info.speed * 10 == i) {
      i = 0;
      state = SHIFTING;
      updateCurrentState_snake(&data, &state, user_n, input);
    }
    render_game_snake(&data);
    nanosleep(&ts, NULL);
    i++;
  }
}
