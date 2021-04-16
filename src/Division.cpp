#include <iostream>

#include "include/Division.h"

Division::Division(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

void Division::afficher() const
{
    getGauche()->afficher();
    std::cout << "/";
    getDroite()->afficher();
}

void Division::afficherNpi() const
{
    getGauche()->afficherNpi();
    std::cout << " ";
    getDroite()->afficherNpi();
    std::cout << " /";
}

float Division::calculer() const
{
    return getGauche()->calculer() / getDroite()->calculer();
}
