#include "include/mainwindow.h"
#include "ui_mainwindow.h"

#include "include/graph2d/graph2dwindow.h"
#include "include/user_input_ihm/UserInputWindow.h"

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
 replaceCentralWidget(new UserInputWindow(this));
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
    replaceCentralWidget(new Graph2DWindow(this));
}

void MainWindow::on_actionGraphical_3D_Print_triggered()
{

}

void MainWindow::on_actionSimplify_Expression_triggered()
{

}

void MainWindow::replaceCentralWidget(QWidget *newOne){
    QWidget* curWidget = centralWidget();
    setCentralWidget(newOne);
    curWidget->deleteLater();
}
