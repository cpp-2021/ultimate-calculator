#ifndef RACINECARRE_H
#define RACINECARRE_H

#include <cmath>
#include "Constante.h"


class RacineCarre: public Constante
{
    public:
        RacineCarre(float f);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};


#endif // RACINECARRE_H
