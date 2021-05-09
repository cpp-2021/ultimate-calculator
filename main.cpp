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
    cout << "Constantes : ";
    c1.afficher();
    cout << ", ";
    c2.afficher();
    cout << endl;

    Addition add1(&c1, &c2);
    Constante resultat(add1.calculer());
    add1.afficher();
    cout << " = ";
    resultat.afficher();
    cout << endl;

    Division div1(&c1, &c2);
    Constante resultat4(div1.calculer());
    //Division *resultat4(div1.simplifier());
    div1.afficher();
    cout << " = ";
    resultat4.afficher();
    cout << endl;

    Multiplication expr(&add1, &div1);
    //Constante res(expr.calculer());
    Multiplication *res(expr.simplifier());
    expr.afficher();
    cout << " = ";
    res->afficher();
    cout << endl;

    return a.exec();
}
