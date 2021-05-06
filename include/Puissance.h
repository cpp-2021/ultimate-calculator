#ifndef PUISSANCE_H
#define PUISSANCE_H
#include <cmath>
#include "Operation.h"


class Puissance: public Operation
{
    public:
        Puissance(Expression *gauche, Expression *droite);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};

#endif // PUISSANCE_H
