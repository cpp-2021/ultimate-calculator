#include "include/ValAbsolue.h"

#include <iostream>
ValAbsolue::ValAbsolue(float f) : Constante(f){}

std::string ValAbsolue::toString() const
{
    return "|" + std::to_string(getValeur()) + "|";
}

std::string ValAbsolue::toStringNpi() const
{
    return std::to_string(getValeur()) + "||";
}

float ValAbsolue::calculer() const
{
    return  abs(getValeur());
}

