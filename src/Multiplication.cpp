#include <iostream>

#include "include/Multiplication.h"
#include "include/variable.h"

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

Multiplication* Multiplication::simplifier() {
    float a = getGauche()->calculer();
    float b = getDroite()->calculer();

    return new Multiplication(new Variable(a), new Variable(b));
}
