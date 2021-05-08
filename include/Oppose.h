#ifndef OPPOSE_H
#define OPPOSE_H

#include "Constante.h"


class Oppose: public Constante
{
    public:
        Oppose(float f);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
};


#endif // OPPOSE_H
