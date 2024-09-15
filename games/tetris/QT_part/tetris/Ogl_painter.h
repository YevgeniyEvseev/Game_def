#ifndef OGL_PAINTER_H
#define OGL_PAINTER_H

#include <QOpenGLWidget>

extern "C" {
#include "../../tetris.h"
}

struct Field {
  int width;
  int height;
  int c_row;
  int c_col;
};

class OGL_painter : public QOpenGLWidget {
 private:
  Field main_w;
  Tetris *data;

 protected:
  virtual void initializeGL();
  virtual void resizeGL(int nWidth, int nHeight);
  virtual void paintGL();

 public:
  OGL_painter(QWidget *pwgt = 0, int n_width = 300, int n_height = 600);
  void print_base_field();
  void draw_point(int n_cow, int n_row, bool type);
  void draw_rectangle(int right, int left, int top, int bottom);
  void render_interface();
  void tetris_game(const char *user);
};

#endif  // OGL_PAINTER_H
