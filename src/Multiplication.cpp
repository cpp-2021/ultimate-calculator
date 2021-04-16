#include <iostream>

#include "include/Multiplication.h"

Multiplication::Multiplication(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

void Multiplication::afficher() const
{
    getGauche()->afficher();
    std::cout << "*";
    getDroite()->afficher();
}

void Multiplication::afficherNpi() const
{
    getGauche()->afficherNpi();
    std::cout << " ";
    getDroite()->afficherNpi();
    std::cout << " *";
}

float Multiplication::calculer() const
{
    return getGauche()->calculer() * getDroite()->calculer();
}
