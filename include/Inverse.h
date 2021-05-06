#ifndef INVERSE_H
#define INVERSE_H

#include "Constante.h"


class Inverse: public Constante
{
    public:
        Inverse(float f);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};

#endif // INVERSE_H
