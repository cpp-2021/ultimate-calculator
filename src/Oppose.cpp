#include "include/Oppose.h"

#include <iostream>

Oppose::Oppose(float f) : Constante(f){}

void Oppose::afficher() const
{
    std::cout << "(0";
    std::cout << "-";
    getValeur();
    std::cout << ")";
}

void Oppose::afficherNpi() const
{
    std::cout << "(0";
    getValeur();
    std::cout << " ";
    std::cout << " -)";
}

float Oppose::calculer() const
{
    return  0 - getValeur();
}
