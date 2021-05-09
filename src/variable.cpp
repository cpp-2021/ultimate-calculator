#include "include/variable.h"
#include <iostream>
#include <string>

Variable::~Variable(){}

Variable::Variable(std::string n, float f){
    _nom = n;
    _valeur = f;
}

std::string Variable::toString() const{
    return _nom;
}

std::string Variable::toStringNpi() const{
    return _nom;
}

void Variable::afficher() const
{
    std::cout << toString();
}

void Variable::afficherNpi() const
{
     std::cout << toStringNpi();
}
