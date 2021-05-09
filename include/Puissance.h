#ifndef PUISSANCE_H
#define PUISSANCE_H
#include <cmath>
#include "Operation.h"


class Puissance: public Operation
{
    public:
        Puissance(Expression *gauche, Expression *droite);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};

#endif // PUISSANCE_H
