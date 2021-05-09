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
    connect(ui->ButtonDiv, SIGNAL(released()), this,
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

    // Connect NPI Button
    connect(ui->ButtonNpiClassic, SIGNAL(released()), this,
            SLOT(NpiSwitchButton()));

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
    if(tabExpression[1] != ""){
        EqualButton();
    }
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
    Expression *expr = nullptr;

    Expression *curExpression = RootExpressionSingleton::instance().get();
    Expression *membreGauche;
    if(curExpression != nullptr){
        membreGauche = curExpression;
    }else{
        membreGauche = new Constante(tabExpression[0].toFloat());
    }

    Expression *membreDroite = new Constante(tabExpression[2].toFloat());

    QByteArray ba = tabExpression[1].toLocal8Bit();
    const char* op = ba.data();
    switch (op[0]){
        case '+':
            expr = new Addition(membreGauche, membreDroite);
            break;
        case '-':
            expr = new Soustraction(membreGauche, membreDroite);
            break;
        case '*':
            expr = new Multiplication(membreGauche, membreDroite);
            break;
        case '/':
            expr = new Division(membreGauche, membreDroite);
            break;
        case 'x':
            expr = new Carre(membreGauche);
            break;
        case 'l':
            expr = new Inverse(membreGauche);
            break;
        case '(':
            expr = new Oppose(membreGauche);
            break;
        case '|':
            expr = new ValAbsolue(membreGauche);
            break;
        case 'L':
            expr = new Ln(membreGauche);
            break;
        case 'v':
            expr = new RacineCarre(membreGauche);
            break;
        case 'p':
            expr = new Puissance(membreGauche, membreDroite);
            break;

        default:
            cout << "Non gere : " << op[0] << endl;
            break;
    }

    if(tabExpression[0] == "")
        return;

    RootExpressionSingleton::instance().set(expr);
    float res =  RootExpressionSingleton::instance().get()->calculer();
    ui->Display->setText(QString::number(res));
    std::cout << res << std::endl;
    QString finalRes = QString::number(res);
    chaineRentree = finalRes;

    refreshExprDisplay();
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
    ui->Expression->setText("");
    delete RootExpressionSingleton::instance().get();
}

void UserInputWindow::AddVirgule(){
    chaineRentree += '.';
    ui->Display->setText(ui->Display->text() + ".");
}

void UserInputWindow::NpiSwitchButton(){
    _npiMode = !_npiMode;
    refreshExprDisplay();
}

void UserInputWindow::refreshExprDisplay(){
    if(chaineRentree == "")
        return;

    std::string tmp = "";
    Constante res(RootExpressionSingleton::instance().get()->calculer());
    if(_npiMode){
        tmp = RootExpressionSingleton::instance().get()->toStringNpi();
    }else{
        tmp = RootExpressionSingleton::instance().get()->toString();
    }
    tmp += " = " + res.toString();

    QString p(tmp.c_str());
    ui->Expression->setText(p);
}
