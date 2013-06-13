#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::display()
{
    ui->openline2->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}
