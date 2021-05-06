#include "include/Ln.h"

#include <iostream>

Ln::Ln(float f) : Constante(f){}

void Ln::afficher() const
{
    std::cout << "(ln(";
    getValeur();
    std::cout << "))";
}

void Ln::afficherNpi() const
{
    std::cout << "(";
    getValeur();
    std::cout << " ";
    std::cout << "ln())";
}

float Ln::calculer() const
{
    return  log(getValeur());
}
