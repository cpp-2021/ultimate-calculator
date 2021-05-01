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

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
        virtual std::string getString() const;
        virtual std::string getStringNpi() const;

        virtual ~Constante();
};

#endif // CONSTANTE_H
