#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "Operation.h"

class Soustraction : public Operation
{
    public:
        Soustraction(Expression *gauche, Expression *droite);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
        virtual std::string getString() const;
        virtual std::string getStringNpi() const;
};

#endif // SOUSTRACTION_H
