#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"

class Multiplication: public Operation
{
    public:
        Multiplication(Expression *gauche, Expression *droite);

        void afficher() const;
        void afficherNpi() const;
        float calculer() const;
        virtual std::string getString() const;
        virtual std::string getStringNpi() const;
};

#endif // MULTIPLICATION_H
