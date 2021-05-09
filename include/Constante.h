#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"

class Constante : public Expression
{
    protected:
        float _valeur;
    public:
        // La valeur par defaut de f permet a ce constructeur de faire office
        // de constructeur par defaut.
        Constante(float f = 0.0f);

        float getValeur() const { return _valeur; }

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;

        virtual ~Constante();
};

#endif // CONSTANTE_H
