#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
    public:
        virtual void afficher() const = 0;
        virtual void afficherNpi() const = 0;
        virtual float calculer() const = 0;
};

#endif // EXPRESSION_H
