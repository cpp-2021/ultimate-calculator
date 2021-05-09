#include "include/Inverse.h"

#include <iostream>
Inverse::Inverse(Expression* exp) : _toInverse(exp) {

}

std::string Inverse::toString() const
{
    return "(1 /" + _toInverse->toString() + ")";
}

std::string Inverse::toStringNpi() const
{
    return "(1 " + _toInverse->toStringNpi() + " /)";
}

float Inverse::calculer() const
{
    return  1 / _toInverse->calculer();
}
