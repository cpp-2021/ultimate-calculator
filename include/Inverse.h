#ifndef INVERSE_H
#define INVERSE_H

#include "Operation.h"


class Inverse: public Expression
{
    private:
    Expression *_toInverse;

    public:
        Inverse(Expression *exp);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};

#endif // INVERSE_H
