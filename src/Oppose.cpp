#include "include/Oppose.h"

#include <iostream>

Oppose::Oppose(float f) : Constante(f){}

std::string Oppose::toString() const
{
    return "(-" + std::to_string(getValeur()) + ")";
}

std::string Oppose::toStringNpi() const
{
    return "(0 " + std::to_string(getValeur()) + " -)";
}

float Oppose::calculer() const
{
    return  0 - getValeur();
}
