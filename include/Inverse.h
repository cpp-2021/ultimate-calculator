#ifndef INVERSE_H
#define INVERSE_H

#include "Operation.h"


class Inverse: public Expression
{
    private:
    Expression *_toInverse;

    public:
        Inverse(Expression *exp);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};

#endif // INVERSE_H
