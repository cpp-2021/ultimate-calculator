#include "include/ValAbsolue.h"

#include <iostream>
ValAbsolue::ValAbsolue(float f) : Constante(f){}

void ValAbsolue::afficher() const
{
    std::cout << "(|";
    getValeur();
    std::cout << "|)";
}

void ValAbsolue::afficherNpi() const
{
    std::cout << "(|";
    getValeur();
    std::cout << " ";
    std::cout << " |)";
}

float ValAbsolue::calculer() const
{
    return  abs(getValeur());
}

