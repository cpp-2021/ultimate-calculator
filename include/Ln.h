#ifndef LN_H
#define LN_H

#include <cmath>
#include "Constante.h"


class Ln: public Constante
{
    public:
        Ln(float f);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};


#endif // LN_H
