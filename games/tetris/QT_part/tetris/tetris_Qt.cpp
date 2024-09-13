#include <QApplication>
#include <iostream>

#include "../../../../define.h"
#include "mainwindow.h"

void tetris(const char* user_n, int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;

  Tetris* data = new Tetris();
  state_game state = START;
  bool flag_play = true;

  char* path = "games/tetris/user_data.txt";
  int offset_char_in_file = 0, i = 0;

  struct timespec ts = {
      .tv_sec = 0,          // nr of secs
      .tv_nsec = 10000000L  // nr of nanosecs
  };

  init_game_info(data);
  data->info.high_score = read_file(user_n, path, &offset_char_in_file);

  while (flag_play) {
    int input;
    std::cin >> input;
    updateCurrentState(data, &state, user_n, input);
    if (state == EXIT_STATE) {
      flag_play = false;
      save_file(&data->info, path, user_n, data->info.score,
                offset_char_in_file);
    }
    if (data->info.speed * 10 == i) {
      i = 0;
      state = SHIFTING;
      updateCurrentState(data, &state, user_n, input);
    }
    // render_field(&data);
    nanosleep(&ts, NULL);
    i++;
  }

  w.show();
  a.exec();
}
