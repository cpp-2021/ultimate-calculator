#include <iostream>

#include "include/Soustraction.h"

Soustraction::Soustraction(Expression *gauche, Expression *droite) : Operation(gauche, droite) {}

void Soustraction::afficher() const
{
    std::cout << "(";
    getGauche()->afficher();
    std::cout << "-";
    getDroite()->afficher();
    std::cout << ")";
}

void Soustraction::afficherNpi() const
{
    std::cout << "(";
    getGauche()->afficherNpi();
    std::cout << " ";
    getDroite()->afficherNpi();
    std::cout << " -)";
}

float Soustraction::calculer() const
{
    return getGauche()->calculer() - getDroite()->calculer();
}
