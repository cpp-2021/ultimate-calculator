#ifndef DIVISION_H
#define DIVISION_H

#include "Operation.h"

class Division: public Operation
{
    public:
        Division(Expression *gauche, Expression *droite);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
        virtual std::string getString() const;
        virtual std::string getStringNpi() const;
};

#endif // DIVISION_H
