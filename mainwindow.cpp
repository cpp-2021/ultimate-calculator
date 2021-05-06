#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "Constante.h"
#include "Addition.h"
#include "Division.h"
#include "Multiplication.h"
#include "Soustraction.h"
#include "Expression.h"
#include "Operation.h"

using namespace std;

bool waitMember = false;
Expression *racine = NULL;

QString chaineRentrée = " ";
QString tabExpression[3];
Expression *expr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText(chaineRentrée);

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
    chaineRentrée += valeur;
}

void MainWindow::MathButtonPressed(char operateur){

    Constante *cons = new Constante(chaineRentrée.toFloat());
    tabExpression[0] = chaineRentrée;
    tabExpression[1] = operateur;
    chaineRentrée = "";
}

void MainWindow::EqualButton()
{
    tabExpression[2] = chaineRentrée;
    chaineRentrée = "";
    Constante *membreGauche = new Constante(tabExpression[0].toFloat());
    Constante *membreDroite = new Constante(tabExpression[2].toFloat());

    QByteArray ba = tabExpression[1].toLocal8Bit();
    const char* op = ba.data();
    switch (op[0]){
        case '+':
            expr = new Addition(membreGauche, membreDroite);
            break;
    }
    expr->calculer();
    std::cout << expr->calculer() << std::endl;


    /*
     * // Holds new calculation
    Constante solution = Constante(0);

    // Get value in display
    QString displayVal = ui->Display->text();
    Expression dblDisplayVal = Constante(displayVal.toFloat());

    // Make sure a math button was pressed
    if(addTrigger || subTrigger || mulTrigger || divTrigger ){
        if(addTrigger){
            Addition add = Addition(&calcVal, &dblDisplayVal);
            solution = add.calculer()
        } else if(subTrigger){
            Soustraction sous = Soustraction(&calcVal, &dblDisplayVal)
            solution = sous.calculer();
        } else if(mulTrigger){
            Multiplication mul = Multiplication(&calcVal, &dblDisplayVal);
            solution = mul.calculer();
        } else {
            Division div = Division(&calcVal, &dblDisplayVal);
            solution = div.calculer();
        }
    }

    // Put solution in display
    ui->Display->setText(QString::number(solution.calculer()));

    solution.afficherNpi(); */

}

void MainWindow::ClearButton(){
    ui->Display->setText("");
}

void MainWindow::AddVirgule(){
    ui->Display->setText(ui->Display->text() + ".");
}


