#include <iostream>

#include "include/Division.h"
#include "include/variable.h"

Division::Division(Expression *gauche, Expression *droite) : Operation(gauche, droite){}

void Division::afficher() const
{
    getGauche()->afficher();
    std::cout << "/";
    getDroite()->afficher();
}

void Division::afficherNpi() const
{
    getGauche()->afficherNpi();
    std::cout << " ";
    getDroite()->afficherNpi();
    std::cout << " /";
}

float Division::calculer() const
{
    return getGauche()->calculer() / getDroite()->calculer();
}

Division* Division::simplifier() {
    float a = getGauche()->calculer();
    float b = getDroite()->calculer();

    if(a == 0 && b == 0){
        return new Division(getGauche(), getDroite());
    }
    if(a == 0){
         return new Division(getGauche(), new Constante(b));

    }
    if(b == 0){
        return new Division(new Constante(a), getDroite());
    }

    return new Division(new Constante(a), new Constante(b));
}
