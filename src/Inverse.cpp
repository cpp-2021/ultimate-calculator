#include "include/Inverse.h"

#include <iostream>
Inverse::Inverse(float f) : Constante(f){}

std::string Inverse::toString() const
{
    return "(1 /" + std::to_string(getValeur()) + ")";
}

std::string Inverse::toStringNpi() const
{
    return "(1 " + std::to_string(getValeur()) + " /)";
}

float Inverse::calculer() const
{
    return  1 / getValeur();
}
