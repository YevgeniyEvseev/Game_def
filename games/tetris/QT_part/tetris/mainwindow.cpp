#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Ogl_painter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OGL_painter *new_painter=new OGL_painter();
    ui->gridLayout->addWidget(new_painter,0,1);
    new_painter->resize(300,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

