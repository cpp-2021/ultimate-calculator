#include <iostream>

#include "include/Division.h"

Division::Division(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

std::string Division::toString() const
{
    return getGauche()->toString() + "/" + getDroite()->toString();
}

std::string Division::toStringNpi() const
{
    return getGauche()->toStringNpi() + " " + getDroite()->toStringNpi();
}

float Division::calculer() const
{
    return getGauche()->calculer() / getDroite()->calculer();
}
