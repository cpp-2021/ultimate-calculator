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
float calcVal = 0;
bool divTrigger = false;
bool mulTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText(QString::number(calcVal));

    // Connect signals and slots for number buttons
    QPushButton *numButton[10];
    for(int i=0; i<10; ++i){
        QString button = "Button" + QString::number(i);
        numButton[i] = MainWindow::findChild<QPushButton *>(button);
        connect(numButton[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }


    // Connect signals and slots for math buttons
    connect(ui->ButtonAdd, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonMinus, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonMult, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonEquals, SIGNAL(released()), this,
            SLOT(EqualButton()));

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
void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    QString displayVal = ui->Display->text();
    if(displayVal.toFloat() == 0){
        ui->Display->setText(displayVal + butval);
    } else {
        QString newVal = displayVal + butval;
        float dblNewVal = newVal.toFloat();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void MainWindow::MathButtonPressed(){

    // Cancel out previous math button clicks
    divTrigger = false;
    mulTrigger = false;
    addTrigger = false;
    subTrigger = false;

    // Store current value in Display
    QString displayVal = ui->Display->text();
    Expression calcVal = Constante(displayVal.toFloat());

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        mulTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else {
        subTrigger = true;
    }

    // Clear display
    ui->Display->setText("");

}

void MainWindow::EqualButton(){

    // Holds new calculation
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

    solution.afficherNpi();

}

void MainWindow::ClearButton(){
    ui->Display->setText("");
}

void MainWindow::AddVirgule(){
    ui->Display->setText(ui->Display->text() + ".");
}


