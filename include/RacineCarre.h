#ifndef RACINECARRE_H
#define RACINECARRE_H

#include <cmath>
#include "Constante.h"


class RacineCarre: public Expression
{
    private:
    Expression *_toSquareRoot;

    public:
        RacineCarre(Expression *exp);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};


#endif // RACINECARRE_H
