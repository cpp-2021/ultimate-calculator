#include <iostream>

#include "include/Constante.h"

Constante::Constante(float f) : _valeur(f){}

std::string Constante::toString() const
{
    return std::to_string(getValeur());
}

std::string Constante::toStringNpi() const
{
    return toString();
}

float Constante::calculer() const
{
    return getValeur();
}

Constante::~Constante(){}
