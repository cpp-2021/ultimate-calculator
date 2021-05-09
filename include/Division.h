#ifndef DIVISION_H
#define DIVISION_H

#include "Operation.h"
#include "variable.h"

class Division: public Operation
{
    public:
        Division(Expression *gauche, Expression *droite);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
        Division* simplifier();
};

#endif // DIVISION_H
