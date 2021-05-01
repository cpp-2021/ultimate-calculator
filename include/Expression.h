#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

class Expression
{
    public:
        virtual void afficher() const = 0;
        virtual void afficherNpi() const = 0;
        virtual float calculer() const = 0;
        virtual std::string getString() const = 0;
        virtual std::string getStringNpi() const = 0;
};

#endif // EXPRESSION_H
