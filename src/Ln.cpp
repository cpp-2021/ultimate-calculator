#include "include/Ln.h"

#include <iostream>

Ln::Ln(Expression *exp) : _toLn(exp){}

std::string Ln::toString() const
{
    return "(ln(" + _toLn->toString() + "))";
}

std::string Ln::toStringNpi() const
{
    return "(" + _toLn->toStringNpi() + " ln())";
}

float Ln::calculer() const
{
    return  log(_toLn->calculer());
}

Expression* Ln::simplifier(){
    return this;
}
