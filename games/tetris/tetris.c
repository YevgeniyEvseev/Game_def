#include "tetris.h"

#include <ncurses.h>
#include <time.h>

#include "../../define.h"
#include "fronted/define.h"

void tetris(const char* user_n) {
  int flag_play = TRUE;
  GameInfo_t data;
  int offset_char_in_file = 0, i = 0;
  state_game state = START;
  struct timespec ts = {
      .tv_sec = 0,                    // nr of secs
      .tv_nsec = 0.001 * 1000000000L  // nr of nanosecs
  };
  init_game_info(&data);
  data.high_score = read_file(user_n, &offset_char_in_file);
  data.score = 1000;
  load_interface();
  while (flag_play) {
    int input = getch();
    updateCurrentState(&data, &state, user_n, input);
    if (state == GAMEOVER) {
      state = EXIT_STATE;
      render_game_over();
      refresh();
      getch();
    }
    if (state == EXIT_STATE) {
      flag_play = false;
      save_file(&data, user_n, data.score, offset_char_in_file);
    }
    if (data.speed == i) {
      i = 0;
      state = SHIFTING;
      updateCurrentState(&data, &state, user_n, input);
      mvprintw(0, 0, "shifting");
    }
    render_field(&data);
    nanosleep(&ts, NULL);
    i++;
  }
}

void tetris_consol(const char* user_n) {}