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
Expression* Addition::simplifier() const{
    //if((isAlpha(getGauche())==)||getDroite())
    return getGauche()->calculer()+getDroite()->calculer();
}*/

        //getGauche() -> constante et idem droite
        //addition constante
        //cast en cosntante et on return
