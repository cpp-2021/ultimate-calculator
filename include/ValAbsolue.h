#ifndef VALABSOLUE_H
#define VALABSOLUE_H


#include <stdlib.h>
#include "Constante.h"


class ValAbsolue: public Constante
{
    public:
        ValAbsolue(float f);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};

#endif // VALABSOLUE_H
