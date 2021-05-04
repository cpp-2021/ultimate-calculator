#ifndef VARIABLE_H
#define VARIABLE_H

#include "Operation.h"

class Variable : public Expression
{
public:
//l'appel a toutes les fonctions
    Variable(float f = 0.0f);

    float getValeur() const { return _valeur; }


    void afficher() const;
    void afficherNpi() const;
    float calculer() const;

private:
    float _valeur;
};
#endif // VARIABLE_H
