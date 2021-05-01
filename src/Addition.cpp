#include <iostream>

#include "include/Addition.h"

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

std::string Addition::getString() const
{
    std::string g = getGauche()->getString();
    std::string d = getDroite()->getString();
    return "( " + g + " + " + d + " )";
}

std::string Addition::getStringNpi() const
{
    std::string g = getGauche()->getStringNpi();
    std::string d = getDroite()->getStringNpi();
    return "( " + g + " " + d + " + " + " )";
}
