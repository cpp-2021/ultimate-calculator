#include <iostream>

#include "include/Division.h"
#include "include/Constante.h"
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
    int xxxx = getGauche()->calculer();
    int yyyy = getDroite()->calculer();
    if(xxxx == 0 && yyyy== 0){
        return new Division(getGauche(), getDroite());
    }
    if(xxxx==0){
         return new Division(getGauche(), new Constante(yyyy));

    }
    if(yyyy==0){
                return new Division(new Constante(xxxx), getDroite());
    }
    return new Division(new Constante(xxxx), new Constante(yyyy));
}
