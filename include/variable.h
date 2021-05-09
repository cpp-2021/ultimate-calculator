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

    Variable(std::string n, float f = 0.0f);

    std::string toString() const;
    std::string toStringNpi() const;

    //Workaround
    void afficher() const override;
    void afficherNpi() const override;

    virtual ~Variable();
};

#endif // VARIABLE_H
