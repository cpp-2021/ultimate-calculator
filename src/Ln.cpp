#include "include/Ln.h"

#include <iostream>

Ln::Ln(float f) : Constante(f){}

std::string Ln::toString() const
{
    return "(ln(" + std::to_string(getValeur()) + "))";
}

std::string Ln::toStringNpi() const
{
    return "(" + std::to_string(getValeur()) + " ln())";
}

float Ln::calculer() const
{
    return  log(getValeur());
}
