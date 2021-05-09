#ifndef ADDITION_H
#define ADDITION_H

#include "Operation.h"

class Addition: public Operation
{
    public:
        Addition(Expression *gauche, Expression *droite);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};

#endif // ADDITION_H
