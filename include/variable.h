#ifndef VARIABLE_H
#define VARIABLE_H

#include "Constante.h"
#include <string>

class Variable: public Constante
{
private:
    std::string _nom;
public:
    Variable();

    Variable(std::string n = "x") { _nom = n; }
    Variable(float f = 0.0f) : Constante(f) {}

    std::string getValeur() const { return _nom; }

    virtual ~Variable();
};

#endif // VARIABLE_H
