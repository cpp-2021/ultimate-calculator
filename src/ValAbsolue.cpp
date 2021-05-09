#include "include/ValAbsolue.h"

#include <iostream>
ValAbsolue::ValAbsolue(Expression *exp) : _toAbsolute(exp){}

std::string ValAbsolue::toString() const
{
    return "|" + _toAbsolute->toString() + "|";
}

std::string ValAbsolue::toStringNpi() const
{
    return _toAbsolute->toStringNpi() + "||";
}

float ValAbsolue::calculer() const
{
    return  abs(_toAbsolute->calculer());
}

Expression* ValAbsolue::simplifier(){
    return this;
}
