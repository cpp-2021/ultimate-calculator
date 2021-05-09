#ifndef OPPOSE_H
#define OPPOSE_H

#include "Constante.h"


class Oppose: public Expression
{
    private:
    Expression *_toOpposite;

    public:
        Oppose(Expression *exp);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;

        Expression* simplifier() override;
};


#endif // OPPOSE_H
