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

    Variable(std::string n = "x");

    std::string getValeur() const { return _nom; }

    virtual ~Variable();
};

#endif // VARIABLE_H
