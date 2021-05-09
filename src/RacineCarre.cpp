#include "include/RacineCarre.h"

#include <iostream>
RacineCarre::RacineCarre(float f) : Constante(f){}

std::string RacineCarre::toString() const
{
    return "√(" + std::to_string(getValeur()) + ")";
}

std::string RacineCarre::toStringNpi() const
{
    return "(" + std::to_string(getValeur()) + ")√";
}

float RacineCarre::calculer() const
{
    return  sqrt(getValeur());
}
