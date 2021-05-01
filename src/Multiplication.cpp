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

std::string Multiplication::getString() const
{
    std::string g = getGauche()->getString();
    std::string d = getDroite()->getString();
    return "( " + g + " * " + d + " )";
}

std::string Multiplication::getStringNpi() const
{
    std::string g = getGauche()->getStringNpi();
    std::string d = getDroite()->getStringNpi();
    return "( " + g + " " + d + " * " + " )";
}
