#include "mainwindow.h"

#include <QApplication>
#include <iostream>

#include "include/Constante.h"
#include "include/variable.h"

#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"

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
/*
    Expression* simpli(add1.simplifier());
    add1.afficher();
    cout << " = ";
    simpli->afficher();
    cout << endl;
*/

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

    Variable v1("a");
    Constante c3(10.0f);
    Division div2(&v1, &c3);
    Division* resultat5(div2.simplifier());
    div2.afficher();
    cout << " = ";
    resultat5->afficher();
    cout << endl;

    Multiplication expr(&add1, &div1);
    Constante res(expr.calculer());
    expr.afficher();
    cout << " = ";
    res.afficher();
    cout << endl;

    expr.afficherNpi();
    cout << endl;

    return 0;
}
