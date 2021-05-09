#ifndef VALABSOLUE_H
#define VALABSOLUE_H


#include <stdlib.h>
#include "Constante.h"


class ValAbsolue: public Constante
{
    public:
        ValAbsolue(float f);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};

#endif // VALABSOLUE_H
