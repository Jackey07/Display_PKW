#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_R)
    {
        ui->label->setText("R");
    }
    else if (e->key() == Qt::Key_1)
    {
        ui->label->setText("1");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

