#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"

class Multiplication: public Operation
{
    public:
        Multiplication(Expression *gauche, Expression *droite);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};

#endif // MULTIPLICATION_H
