#include "include/ValAbsolue.h"

#include <iostream>
ValAbsolue::ValAbsolue(Expression *exp) : _toAbsolute(exp){}

std::string ValAbsolue::toString() const
{
    return "|" + _toAbsolute->toString() + "|";
}

std::string ValAbsolue::toStringNpi() const
{
    return _toAbsolute->toString() + "||";
}

float ValAbsolue::calculer() const
{
    return  abs(_toAbsolute->calculer());
}

