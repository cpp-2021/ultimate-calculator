#ifndef OPERATION_H
#define OPERATION_H

#include "Expression.h"

class Operation: public Expression
{
    private:
        Expression *_gauche;
        Expression *_droite;
    public:
        Operation(Expression *gauche, Expression *droite): _gauche(gauche), _droite(droite){}

        Expression *getGauche() const { return _gauche; }
        Expression *getDroite() const { return _droite; }

        virtual void afficher() const = 0;
        virtual void afficherNpi() const = 0;
        virtual float calculer() const = 0;
        virtual std::string getString() const = 0;
        virtual std::string getStringNpi() const = 0;

};

#endif // OPERATION_H
