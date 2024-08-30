#include "tetris.h"

#include <ncurses.h>
#include <time.h>

#include "../../define.h"
#include "fronted/define.h"

void tetris_consol(const char* user_n) {
  int flag_play = TRUE;
  GameInfo_t data;
  int offset_char_in_file = 0, i = 0;
  state_game state = START;
  struct timespec ts = {
      .tv_sec = 0,                         // nr of secs
      .tv_nsec = 0.001 * 10 * 1000000000L  // nr of nanosecs
  };
  init_game_info(&data);
  data.high_score = read_file(user_n, &offset_char_in_file);
  data.score = 0;
  load_interface();
  while (flag_play) {
    int input = getch();
    updateCurrentState(&data, &state, user_n, input);
    if (state == EXIT_STATE) {
      flag_play = false;
      save_file(&data, user_n, data.score, offset_char_in_file);
    }

    if (data.speed * 10 == i) {
      i = 0;
      state = SHIFTING;
      updateCurrentState(&data, &state, user_n, input);
    }
    render_field(&data);
    nanosleep(&ts, NULL);
    i++;
  }
}

void tetris(const char* user_n) {}