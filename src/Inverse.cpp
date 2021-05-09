#include "include/Inverse.h"

#include <iostream>
Inverse::Inverse(Expression* exp) : _toInverse(exp) {

}

void Inverse::afficher() const
{
    std::cout << "(1";
    std::cout << "/";
    _toInverse->afficher();
    std::cout << ")";
}

void Inverse::afficherNpi() const
{
    std::cout << "(1";
    std::cout << " ";
    _toInverse->afficherNpi();
    std::cout << " /)";
}

float Inverse::calculer() const
{
    return  1 / _toInverse->calculer();
}
