#include <iostream>

#include "include/Constante.h"

Constante::Constante(float f) : _valeur(f){}

void Constante::afficher() const
{
    std::cout << getValeur();
}

void Constante::afficherNpi() const
{
    afficher();
}

float Constante::calculer() const
{
    return getValeur();
}

std::string Constante::getString() const
{
    return std::to_string(getValeur());
}

std::string Constante::getStringNpi() const
{
    return getString();
}
Constante::~Constante(){}
