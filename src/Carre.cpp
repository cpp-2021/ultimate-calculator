#include "include/Carre.h"

#include <iostream>
Carre::Carre(float f) : Constante(f){}

std::string Carre::toString() const
{
    return std::to_string(getValeur()) + "²";
}

std::string Carre::toStringNpi() const
{
    return toString();
}

float Carre::calculer() const
{
    return  getValeur() * getValeur();
}
