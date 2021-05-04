#include "include/Variable.h"
#include <iostream>

using namespace std;

Variable::Variable(float f) : _valeur(f) {}

void Variable::afficher() const
{
    std::cout << getValeur();
}

void Variable::afficherNpi() const
{
    afficher();

}

float Variable::calculer() const
{
    return getValeur();
}
