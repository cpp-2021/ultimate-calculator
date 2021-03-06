#include "include/Oppose.h"

#include <iostream>

Oppose::Oppose(Expression *exp) : _toOpposite(exp){}

std::string Oppose::toString() const
{
    return "(-" + _toOpposite->toString() + ")";
}

std::string Oppose::toStringNpi() const
{
    return "(0 " + _toOpposite->toStringNpi() + " -)";
}

float Oppose::calculer() const
{
    return  0 - _toOpposite->calculer();
}

Expression* Oppose::simplifier(){
    return this;
}
