#include "include/RacineCarre.h"

#include <iostream>
RacineCarre::RacineCarre(float f) : Constante(f){}

void RacineCarre::afficher() const
{
    std::cout << "(";
    std::cout << "√";
    getValeur();
    std::cout << ")";
}

void RacineCarre::afficherNpi() const
{
    std::cout << "(";
    getValeur();
    std::cout << " ";
    std::cout << " √)";
}

float RacineCarre::calculer() const
{
    return  sqrt(getValeur());
}
