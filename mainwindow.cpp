#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

#include "include/Constante.h"
#include "include/Addition.h"
#include "include/Division.h"
#include "include/Multiplication.h"
#include "include/Soustraction.h"
#include "include/Expression.h"
#include "include/Operation.h"

#include "include/RootExpressionSingleton.h"

using namespace std;

bool waitMember = false;

QString chaineRentree = "";
QString tabExpression[3];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText(chaineRentree);

    // Connect signals and slots for number buttons
    QPushButton *numButton[10];
    for(int i=0; i<10; ++i){
        QString button = "Button" + QString::number(i);
        numButton[i] = MainWindow::findChild<QPushButton *>(button);
        connect(numButton[i], SIGNAL(released()), this, SLOT(NumPressed(QString::number(i))));
    }


    // Connect signals and slots for math buttons
    connect(ui->ButtonAdd, SIGNAL(released()), this,
            SLOT(MathButtonPressed('+')));
    connect(ui->ButtonMinus, SIGNAL(released()), this,
            SLOT(MathButtonPressed('-')));
    connect(ui->ButtonMult, SIGNAL(released()), this,
            SLOT(MathButtonPressed('*')));
    connect(ui->ButtonEquals, SIGNAL(released()), this,
            SLOT(EqualButton('=')));

    // Connect clear button
    connect(ui->ButtonAC, SIGNAL(released()), this,
            SLOT(ClearButton()));

    // Connect comma button
    connect(ui->ButtonVirgule, SIGNAL(released()), this,
            SLOT(AddVirgule()));


}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Function that display the number pressed by the user in the user interface.
void MainWindow::NumPressed(QString valeur){
    chaineRentree += valeur;
}

/**
  * Fill the temp array with left member and operator
  **/
void MainWindow::MathButtonPressed(char operateur){

    Constante *cons = new Constante(chaineRentree.toFloat());
    tabExpression[0] = chaineRentree;
    tabExpression[1] = operateur;
    chaineRentree = "";
}

/**
  * Fill the temp array with right member
  * and instantiate expression (through singleton)
  * according to the right operator
  **/
void MainWindow::EqualButton()
{
    tabExpression[2] = chaineRentree;
    chaineRentree = "";
    Constante *membreGauche = new Constante(tabExpression[0].toFloat());
    Constante *membreDroite = new Constante(tabExpression[2].toFloat());

    QByteArray ba = tabExpression[1].toLocal8Bit();
    const char* op = ba.data();
    switch (op[0]){
      case '+':
        Expression *expr = new Addition(membreGauche, membreDroite);
        RootExpressionSingleton::instance().set(&expr);
        break;
      case '-':
        Expression *expr = new Soustraction(membreGauche, membreDroite);
        RootExpressionSingleton::instance().set(&expr);
        break;
      case '*':
        Expression *expr = new Multiplication(membreGauche, membreDroite);
        RootExpressionSingleton::instance().set(&expr);
        break;
      case '/':
        Expression *expr = new Division(membreGauche, membreDroite);
        RootExpressionSingleton::instance().set(&expr);
        break;
    }

    float res =  RootExpressionSingleton::instance().get()->calculer()
    ui->Display->setText(QString::number(res))


}

/**
  * Empty everything (back to square 1 lol)
  */
void MainWindow::ClearButton(){
    tabExpression = ["", "", ""];
    chaineRentree = "";
    ui->Display->setText(chaineRentree)
}

void MainWindow::AddVirgule(){
    ui->Display->setText(ui->Display->text() + ".");
}
