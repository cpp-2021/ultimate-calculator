#include "include/Carre.h"

#include <iostream>
Carre::Carre(Expression * exp) : _toSquare(exp){}

std::string Carre::toString() const
{
    return _toSquare->toString() + "²";
}

std::string Carre::toStringNpi() const
{
    return _toSquare->toStringNpi() + "²";
}

float Carre::calculer() const
{
    float temp = _toSquare->calculer();
    return temp*temp;
}

Expression* Carre::simplifier(){
    return this;
}
