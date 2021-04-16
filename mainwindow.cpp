#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionsave_triggered()
{

}


void MainWindow::on_actionload_triggered()
{

}

void MainWindow::on_actionEnter_Expression_triggered()
{

}

void MainWindow::on_actionPrint_Classical_Expression_triggered()
{

}

void MainWindow::on_actionPrint_P_I_Expression_triggered()
{

}

void MainWindow::on_actionPrint_Value_Expression_triggered()
{

}

void MainWindow::on_actionGraphical_2D_Print_triggered()
{

}

void MainWindow::on_actionGraphical_3D_Print_triggered()
{

}

void MainWindow::on_actionSimplify_Expression_triggered()
{

}
