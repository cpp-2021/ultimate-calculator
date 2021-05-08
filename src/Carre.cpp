#include "include/Carre.h"

#include <iostream>
Carre::Carre(float f) : Constante(f){}

void Carre::afficher() const
{
    std::cout << "(";
    getValeur();
    std::cout << "*";
    getValeur();
    std::cout << ")";
}

void Carre::afficherNpi() const
{
    std::cout << "(";
    getValeur();
    std::cout << " ";
    getValeur();
    std::cout << " *)";
}

float Carre::calculer() const
{
    return  getValeur() * getValeur();
}
