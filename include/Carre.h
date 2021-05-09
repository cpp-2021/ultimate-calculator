#ifndef CARRE_H
#define CARRE_H


#include "Constante.h"


class Carre: public Constante
{
    public:
        Carre(float f);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};

#endif // CARRE_H
