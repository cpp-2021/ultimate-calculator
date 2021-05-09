#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <iostream>

class Expression
{
    public:
        virtual std::string toString() const = 0;
        virtual std::string toStringNpi() const = 0;

        virtual void afficher() const { std::cout << toString(); }
        virtual void afficherNpi() const { std::cout << toStringNpi(); }
        virtual float calculer() const = 0;

        virtual ~Expression(){}
};

#endif // EXPRESSION_H
