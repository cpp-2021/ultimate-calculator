#include "include/mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include "include/graph2d/graph2dwindow.h"
#include "include/user_input_ihm/UserInputWindow.h"

#include "include/LoadSave.h"

#include "include/RootExpressionSingleton.h"
#include "include/Constante.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    replaceCentralWidget(new UserInputWindow(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionsave_triggered()
{
    save(RootExpressionSingleton::instance().get());
}


void MainWindow::on_actionload_triggered()
{
    Expression *loaded = load();
    RootExpressionSingleton::instance().set(loaded);
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
    newWindow(new Graph2DWindow(nullptr));
}

void MainWindow::on_actionGraphical_3D_Print_triggered()
{

}

void MainWindow::on_actionSimplify_Expression_triggered()
{
   RootExpressionSingleton singleton = RootExpressionSingleton::instance();
   Expression * r = singleton.get();
   if(r != nullptr){
     RootExpressionSingleton::instance().set(r->simplifier());
      RootExpressionSingleton::instance().get()->afficher(); std::cout << std::endl;
     //Affect expression in the central widget
     UserInputWindow* curWidget = (UserInputWindow*) centralWidget();
     curWidget->refreshExprDisplay();
   }
}

void MainWindow::replaceCentralWidget(QWidget *newOne){
    QWidget* curWidget = centralWidget();
    setCentralWidget(newOne);
    curWidget->deleteLater();
}

void MainWindow::newWindow(QWidget *newOne){
    newOne->setParent(nullptr);
    newOne->show();
}
