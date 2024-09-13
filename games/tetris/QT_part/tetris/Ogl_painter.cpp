#include "Ogl_painter.h"

#include <QOpenGLFunctions>

#include "../../../../define.h"

void OGL_painter::initializeGL() {
  QOpenGLFunctions *pFunc = QOpenGLContext::currentContext()->functions();
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
  for (int i = 0; i < COLS; ++i) {
    for (int j = 0; j < ROWS; ++j) {
      if (p_game_tetris->info.field[i][j] == 1) draw_point(i, j, true);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (p_game_tetris->cur_figure.data[i][j] == 1) draw_point(i, j, true);
    }
  }
}

void OGL_painter::render_interface() {
  glLineWidth(2);
  draw_rectangle(1, main_w.width + BOARD + 1, 1, main_w.height + BOARD + 1);
}

OGL_painter::OGL_painter(QWidget *parent, int n_width, int n_height)
    : QOpenGLWidget(parent) {
  main_w.width = n_width;
  main_w.height = n_height;
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
