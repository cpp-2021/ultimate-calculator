#ifndef OPPOSE_H
#define OPPOSE_H

#include "Constante.h"


class Oppose: public Constante
{
    public:
        Oppose(float f);

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;
};


#endif // OPPOSE_H
