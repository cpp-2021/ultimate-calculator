#include <QApplication>
#include <iostream>

#include "include/Constante.h"
#include "include/variable.h"

#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"
#include "include/Puissance.h"

#include "include/RootExpressionSingleton.h"

#include "include/mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Constante c(2.0f);
    cout << Puissance(&c,&c).calculer() << endl;

    MainWindow w;
    w.show();

    
    Constante c1(5.0f);
    Constante c2(3.0f);

    //Création d'une expression avec variable
    cout << "Multiplication avec variable" << endl;
    Variable v("x",3.0f);
    Multiplication m(&c1, &v);
    m.afficher();
    cout << " = ";
    Constante result(m.calculer());
    result.afficher();
    cout << endl;

    return a.exec();
}
