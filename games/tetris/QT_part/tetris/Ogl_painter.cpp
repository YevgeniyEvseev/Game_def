#include "Ogl_painter.h"

#include <QOpenGLFunctions>
#include <iostream>

#include "../../../../define.h"

void OGL_painter::initializeGL() {
  QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
  pFunc->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void OGL_painter::resizeGL(int nWidth, int nHeight) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
  glOrtho(0, main_w.width + 4, main_w.height + 5, 0, -1, 1);
}

void OGL_painter::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  render_interface();
  print_base_field();

  /*
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(0, 100);
    glColor3f(0, 1, 0);
    glVertex2f(100, 100);
    glColor3f(0, 0, 1);
    glVertex2f(100, 0);
    glColor3f(1, 1, 1);
    glVertex2f(0, 0);
    glEnd();
    */
}

void OGL_painter::print_base_field() {
  for (int i = 0; i < COLS; ++i) {
    for (int j = 0; j < ROWS; ++j) {
      if (data->info.field[i][j] == 1) draw_point(i, j, true);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (data->cur_figure.data[i][j] == 1) draw_point(i, j, true);
    }
  }
}

void OGL_painter::render_interface() {
  glLineWidth(2);
  draw_rectangle(1, main_w.width + BOARD + 1, 1, main_w.height + BOARD + 1);
}

OGL_painter::OGL_painter(QWidget* parent, int n_width, int n_height)
    : QOpenGLWidget(parent) {
  main_w.width = n_width;
  main_w.height = n_height;
  data = new Tetris();
}

void OGL_painter::draw_point(int n_cow, int n_row, bool type) {
  if (type != true) {
    return;
  }
  int x = (main_w.width / COLS) * n_cow + 2;
  int y = (main_w.height / ROWS) * n_row + 2;
  int size_length_quad = main_w.width / COLS;
  glLineWidth(2);
  draw_rectangle(x + BOARD, x + size_length_quad - BOARD, y + BOARD,
                 y + size_length_quad - BOARD);
  glBegin(GL_QUADS);
  glVertex2d(x + 4, y + 4);
  glVertex2d(x + size_length_quad - 4, y + 4);
  glVertex2d(x + size_length_quad - 4, y + size_length_quad - 4);
  glVertex2d(x + 4, y + size_length_quad - 4);

  glEnd();
}

void OGL_painter::draw_rectangle(int right, int left, int top, int bottom) {
  glBegin(GL_LINES);
  glColor3f(0, 0, 0);

  glVertex2d(left, top);
  glVertex2d(right, top);

  glVertex2d(right, top);
  glVertex2d(right, bottom);

  glVertex2d(right, bottom);
  glVertex2d(left, bottom);

  glVertex2d(left, bottom);
  glVertex2d(left, top);

  glEnd();
}

void OGL_painter::tetris_game(const char* user_n) {
  state_game state = START;
  bool flag_play = true;

  char* path = "games/tetris/user_data.txt";
  int offset_char_in_file = 0, i = 0;

  struct timespec ts = {
      .tv_sec = 0,          // nr of secs
      .tv_nsec = 10000000L  // nr of nanosecs
  };

  // init_game_info(data);
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
    paintGL();

    nanosleep(&ts, NULL);
    i++;
  }
}
