#ifndef ROOTEXPRESSIONSINGLETON_H
#define ROOTEXPRESSIONSINGLETON_H

#include "include/Expression.h"
#include <iostream>

class RootExpressionSingleton
{
private:
    Expression* _exp = nullptr; //L'expression statique

public:
    //Accesseur instance global
    static RootExpressionSingleton& instance()
    {
        //Approche modernisee du Lazy Init (C++11  s'assure qu'il n'existe qu'une seule variable statique)
         static RootExpressionSingleton * instance = new RootExpressionSingleton();
         return *instance;
    }

    //Definition de l'expression
    void set(Expression * exp){
        _exp = exp;
    }

    //Accesseur pour l'expression
    Expression * get() {
        if(_exp == nullptr){
            std::cout << "Attention ! Vous recuperez une expression non definie (Expression du Singleton null)" << std::endl;
        }
        return _exp;
    }

private:
    RootExpressionSingleton(){}
};

#endif // ROOTEXPRESSIONSINGLETON_H
