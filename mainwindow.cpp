#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("导师登录界面");
    setWindowFlags(Qt::Window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

