#include "include/Puissance.h"
#include <iostream>
Puissance::Puissance(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

std::string Puissance::toString() const
{
    return "(" + getGauche()->toString() + "^" + getDroite()->toString() + ")";
}

std::string Puissance::toStringNpi() const
{
    return "( " + getGauche()->toStringNpi() + " " + getDroite()->toStringNpi() + " ^)";
}

float Puissance::calculer() const
{
    return  pow(getGauche()->calculer(), getDroite()->calculer());
}
