#include "include/user_input_ihm/UserInputWindow.h"
#include "ui_user_input_ihm.h"
#include "iostream"

#include "include/Constante.h"
#include "include/Addition.h"
#include "include/Division.h"
#include "include/Multiplication.h"
#include "include/Soustraction.h"
#include "include/Expression.h"
#include "include/Operation.h"

#include "include/ValAbsolue.h"
#include "include/Inverse.h"
#include "include/Carre.h"
#include "include/Puissance.h"
#include "include/Oppose.h"
#include "include/Ln.h"
#include "include/RacineCarre.h"


#include "include/RootExpressionSingleton.h"

using namespace std;

bool waitMember = false;

QString chaineRentree = "";
QString tabExpression[3] = {"0"};

UserInputWindow::UserInputWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::UserInputWindow), _npiMode(false)
{
    RootExpressionSingleton::instance().set(new Addition(new Constante(0), new Constante(0)));
    ui->setupUi(this);
    ui->Display->setText(chaineRentree);

    // Connect signals and slots for number buttons
    QPushButton *numButton[10];
    for(int i=0; i<10; ++i){
        QString button = "Button" + QString::number(i);
        QString test = "1";
        numButton[i] = UserInputWindow::findChild<QPushButton *>(button);
        connect(numButton[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }


    // Connect signals and slots for math buttons
    connect(ui->ButtonAdd, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonMinus, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonMult, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonCarre, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonRacine, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonLogNeperien, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonAbsolue, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonOppose, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonPuissance, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonInverse, SIGNAL(released()), this,
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
UserInputWindow::~UserInputWindow()
{
    delete ui;
}

// Function that display the number pressed by the user in the user interface.
void UserInputWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    chaineRentree += butval;
    ui->Display->setText(chaineRentree);
}

/**
  * Fill the temp array with left member and operator
  **/
void UserInputWindow::MathButtonPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    Constante *cons = new Constante(chaineRentree.toFloat());
    tabExpression[0] = chaineRentree;
    tabExpression[1] = butval;
    chaineRentree = "";
}

/**
  * Fill the temp array with right member
  * and instantiate expression (through singleton)
  * according to the right operator
  **/
void UserInputWindow::EqualButton()
{
    tabExpression[2] = chaineRentree;
    Expression *expr;
    Constante *membreGauche = new Constante(tabExpression[0].toFloat());
    Constante *membreDroite = new Constante(tabExpression[2].toFloat());

    QByteArray ba = tabExpression[1].toLocal8Bit();
    const char* op = ba.data();
    switch (op[0]){
        case '+':
            expr = new Addition(membreGauche, membreDroite);
            RootExpressionSingleton::instance().set(expr);
            break;
        case '-':
            expr = new Soustraction(membreGauche, membreDroite);
            RootExpressionSingleton::instance().set(expr);
            break;
        case '*':
            expr = new Multiplication(membreGauche, membreDroite);
            RootExpressionSingleton::instance().set(expr);
            break;
        case '/':
            expr = new Division(membreGauche, membreDroite);
            RootExpressionSingleton::instance().set(expr);
            break;
        case 'x':
            expr = new Carre(membreGauche);
            RootExpressionSingleton::instance().set(expr);
            break;
        case 'l':
            expr = new Inverse(membreGauche);
            RootExpressionSingleton::instance().set(expr);
            break;
        case '(':
            expr = new Oppose(membreGauche);
            RootExpressionSingleton::instance().set(expr);
            break;
        case '|':
            expr = new ValAbsolue(membreGauche);
            RootExpressionSingleton::instance().set(expr);
            break;
        case 'L':
            expr = new Ln(membreGauche);
            RootExpressionSingleton::instance().set(expr);
            break;
        case 'v':
            expr = new RacineCarre(membreGauche);
            RootExpressionSingleton::instance().set(expr);
            break;
        case 'p':
            expr = new Puissance(membreGauche, membreDroite);
            RootExpressionSingleton::instance().set(expr);
            break;

        default:
            cout << "Non gere : " << op[0] << endl;
            break;
    }

    float res =  RootExpressionSingleton::instance().get()->calculer();
    ui->Display->setText(QString::number(res));
    std::cout << res << std::endl;
    QString finalRes = QString::number(res);
    chaineRentree = finalRes;

    if(_npiMode){
        QString p(RootExpressionSingleton::instance().get()->toStringNpi().c_str());
        ui->Expression->setText(p);
    }else{
        QString p(RootExpressionSingleton::instance().get()->toString().c_str());
        ui->Expression->setText(p);
    }
}

/**
  * Empty everything (back to square 1 lol)
  */
void UserInputWindow::ClearButton(){
    tabExpression[0] = "";
    tabExpression[1] = "";
    tabExpression[2] = "";
    chaineRentree = "";
    ui->Display->setText(chaineRentree);
    RootExpressionSingleton::instance().set(new Addition(new Constante(0), new Constante(0)));
}

void UserInputWindow::AddVirgule(){
    chaineRentree += '.';
    ui->Display->setText(ui->Display->text() + ".");
}
