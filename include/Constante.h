#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"

class Constante : public Expression
{
    private:
        float _valeur;
    public:
        // La valeur par défaut de f permet a ce constructeur de faire office
        // de constructeur par défaut.
        Constante(float f = 0.0f);

        float getValeur() const { return _valeur; }

        std::string toString() const;
        std::string toStringNpi() const;
        float calculer() const;

        virtual ~Constante();
};

#endif // CONSTANTE_H
