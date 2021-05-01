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
std::string Soustraction::getString() const
{
    std::string g = getGauche()->getString();
    std::string d = getDroite()->getString();
    return "( " + g + " + " + d + " )";
}

std::string Soustraction::getStringNpi() const
{
    std::string g = getGauche()->getStringNpi();
    std::string d = getDroite()->getStringNpi();
    return "( " + g + " " + d + " + " + " )";
}
