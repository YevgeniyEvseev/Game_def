#include "mainwindow.h"

#include <time.h>

#include <QLabel>
#include <iostream>

#include "../../../../define.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  new_painter = new OGL_painter();
  ui->gridLayout->addWidget(new_painter, 0, 1);
}

MainWindow::~MainWindow() {
  delete ui;
  delete new_painter;
  // delete data;
}
