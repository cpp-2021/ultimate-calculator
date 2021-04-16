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

Constante::~Constante(){}
