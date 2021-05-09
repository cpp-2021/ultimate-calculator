#ifndef ADDITION_H
#define ADDITION_H

#include "Operation.h"
#include "Constante.h"

class Addition: public Operation
{
    public:
        Addition(Expression *gauche, Expression *droite);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
        Addition* simplifier();
};

#endif // ADDITION_H
