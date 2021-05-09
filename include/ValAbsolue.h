#ifndef VALABSOLUE_H
#define VALABSOLUE_H


#include <stdlib.h>
#include "Constante.h"


class ValAbsolue: public Expression
{
    private:
        Expression *_toAbsolute;
    public:
        ValAbsolue(Expression *exp);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;

        Expression* simplifier() override;
};

#endif // VALABSOLUE_H
