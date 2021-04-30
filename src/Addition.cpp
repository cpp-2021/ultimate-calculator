#include <iostream>
#include <ctype.h>
#include "include/Addition.h"
#include "include/Constante.h"


Addition::Addition(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

void Addition::afficher() const
{
    std::cout << "(";
    getGauche()->afficher();
    std::cout << "+";
    getDroite()->afficher();
    std::cout << ")";
}

void Addition::afficherNpi() const
{
    std::cout << "(";
    getGauche()->afficherNpi();
    std::cout << " ";
    getDroite()->afficherNpi();
    std::cout << " +)";
}

float Addition::calculer() const
{
    return getGauche()->calculer() + getDroite()->calculer();
}

/*
Expression* Addition::simplifier() {
    int a = getGauche()->calculer();
    int b = getDroite()->calculer();

    return new Division(new Constante(a), new Constante(b));
}*/
