#ifndef LN_H
#define LN_H

#include <cmath>
#include "Constante.h"


class Ln: public Expression
{
    private:
        Expression *_toLn;
    public:
        Ln(Expression *exp);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;

        Expression* simplifier() override;
};


#endif // LN_H
