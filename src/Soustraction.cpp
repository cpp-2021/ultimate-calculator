#include <iostream>

#include "include/Soustraction.h"

Soustraction::Soustraction(Expression *gauche, Expression *droite) : Operation(gauche, droite) {}

std::string Soustraction::toString() const
{
    return "(" + getGauche()->toString() + "-" + getDroite()->toStringNpi() + ")";
}

std::string Soustraction::toStringNpi() const
{
    return "(" + getGauche()->toString() + " " + getDroite()->toStringNpi() + " -)";
}

float Soustraction::calculer() const
{
    return getGauche()->calculer() - getDroite()->calculer();
}
