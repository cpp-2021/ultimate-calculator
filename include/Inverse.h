#ifndef INVERSE_H
#define INVERSE_H

#include "Constante.h"


class Inverse: public Constante
{
    public:
        Inverse(float f);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};

#endif // INVERSE_H
