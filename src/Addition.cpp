#include <iostream>
#include <ctype.h>
#include "include/Addition.h"
#include "include/variable.h"


Addition::Addition(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

std::string Addition::toString() const
{
    return "(" + getGauche()->toString() + "+" + getDroite()->toString() + ")";
}

std::string Addition::toStringNpi() const
{
    return "(" + getGauche()->toString() + " " + getDroite()->toString() + " +)";
}

float Addition::calculer() const
{
    return getGauche()->calculer() + getDroite()->calculer();
}


Addition* Addition::simplifier() {
    float a = getGauche()->calculer();
    float b = getDroite()->calculer();

    return new Addition(new Constante(a), new Constante(b));
}
