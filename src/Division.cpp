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

std::string Division::getString() const
{
    std::string g = getGauche()->getString();
    std::string d = getDroite()->getString();
    return "( " + g + " / " + d + " )";
}

std::string Division::getStringNpi() const
{
    std::string g = getGauche()->getStringNpi();
    std::string d = getDroite()->getStringNpi();
    return "( " + g + " " + d + " / " + " )";
}
