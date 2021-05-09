#ifndef DIVISION_H
#define DIVISION_H

#include "Operation.h"
#include "variable.h"

class Division: public Operation
{
    public:
        Division(Expression *gauche, Expression *droite);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
        Division* simplifier();
};

#endif // DIVISION_H
