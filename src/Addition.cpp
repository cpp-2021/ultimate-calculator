#include <iostream>

#include "include/Addition.h"

Addition::Addition(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

std::string Addition::toString() const
{
    return "(" + getGauche()->toString() + "+" + getGauche()->toString() + ")";
}

std::string Addition::toStringNpi() const
{
    return "(" + getGauche()->toString() + " " + getGauche()->toString() + " +)";
}

float Addition::calculer() const
{
    return getGauche()->calculer() + getDroite()->calculer();
}
