#include "include/graph2d/graph2dwindow.h"

#include <QApplication>

#include <iostream>

#include "include/Constante.h"

#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"

#include "include/RootExpressionSingleton.h"

using namespace std;

int main(int argc, char *argv[])
{
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

    Soustraction sub1(&c1, &c2);
    Constante resultat2(sub1.calculer());
    sub1.afficher();
    cout << " = ";
    resultat2.afficher();
    cout << endl;

    Multiplication mul1(&c1, &c2);
    Constante resultat3(mul1.calculer());
    mul1.afficher();
    cout << " = ";
    resultat3.afficher();
    cout << endl;

    Division div1(&c1, &c2);
    Constante resultat4(div1.calculer());
    div1.afficher();
    cout << " = ";
    resultat4.afficher();
    cout << endl;

    Multiplication expr(&add1, &div1);
    Constante res(expr.calculer());
    expr.afficher();
    cout << " = ";
    res.afficher();
    cout << endl;

    expr.afficherNpi();
    cout << endl;

    QApplication a(argc, argv);
    Graph2DWindow w;
    w.show();

    cout << "Exemple singleton : "<< endl;

    //Définition de l'expression statique
    RootExpressionSingleton::instance().set(&expr);

    //Accès à l'expression
    RootExpressionSingleton::instance().get()->afficher();
    cout << endl;

    return a.exec();
}
