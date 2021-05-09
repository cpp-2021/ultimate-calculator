#include "include/RacineCarre.h"

#include <iostream>
RacineCarre::RacineCarre(Expression *exp) : _toSquareRoot(exp){}

std::string RacineCarre::toString() const
{
    return "√(" + _toSquareRoot->toString() + ")";
}

std::string RacineCarre::toStringNpi() const
{
    return "√(" + _toSquareRoot->toStringNpi() + ")";
}

float RacineCarre::calculer() const
{
    return  sqrt(_toSquareRoot->calculer());
}

Expression* RacineCarre::simplifier(){
    return this;
}
