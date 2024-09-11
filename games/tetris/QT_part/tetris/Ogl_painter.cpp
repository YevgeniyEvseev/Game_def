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
  glOrtho(0, main_w.width + 100, main_w.height, 0, -1, 1);
}

void OGL_painter::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (int i = 0; i < 10; ++i) {
    draw_point(i, 2, true);
  }
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
  const int board = 2;
  int x = (main_w.width / 10) * n_cow;
  int y = (main_w.height / 20) * n_row;
  int size_length_quad = main_w.width / 10;
  glLineWidth(2);
  draw_rectangle(x + board, x + size_length_quad - board, y + board,
                 y + size_length_quad - board);
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
