#include <QApplication>

#include "../../../../define.h"
#include "mainwindow.h"

void tetris(const char* user_n, int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  a.exec();
}
