#include "include/Inverse.h"

#include <iostream>
Inverse::Inverse(float f) : Constante(f){}

void Inverse::afficher() const
{
    std::cout << "(1";
    std::cout << "/";
    getValeur();
    std::cout << ")";
}

void Inverse::afficherNpi() const
{
    std::cout << "(1";
    std::cout << " ";
    getValeur();
    std::cout << " /)";
}

float Inverse::calculer() const
{
    return  1 / getValeur();
}
