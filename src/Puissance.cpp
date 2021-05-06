#include "include/Puissance.h"
#include <iostream>
Puissance::Puissance(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

void Puissance::afficher() const
{
    std::cout << "(";
    getGauche()->afficher();
    std::cout << "^";
    getDroite()->afficher();
    std::cout << ")";
}

void Puissance::afficherNpi() const
{
    std::cout << "(";
    getGauche()->afficherNpi();
    std::cout << " ";
    getDroite()->afficherNpi();
    std::cout << " ^)";
}

float Puissance::calculer() const
{
    return  pow(getGauche()->calculer(), getDroite()->calculer());
}
