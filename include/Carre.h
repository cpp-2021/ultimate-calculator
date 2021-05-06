#ifndef CARRE_H
#define CARRE_H


#include "Constante.h"


class Carre: public Constante
{
    public:
        Carre(float f);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};

#endif // CARRE_H
