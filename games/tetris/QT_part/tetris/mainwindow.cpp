#include "mainwindow.h"

#include <time.h>

#include <QLabel>

#include "../../../../define.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  new_painter = new OGL_painter();
  ui->gridLayout->addWidget(new_painter, 0, 1);

  /*
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    // Here is how to change position:
    // label->setGeometry(QRectF(10, 10, 30, 80));
    */
}

MainWindow::~MainWindow() {
  delete ui;
  delete new_painter;
}
