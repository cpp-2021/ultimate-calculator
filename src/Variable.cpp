#include "variable.h"
#include <iostream>

using namespace std;


Variable::Variable(string nom, float nb)
{
    _csteV = nom;
    this->setValeur(nb);
    next = NULL;
}

void Variable::setValeur(float c)
{
    _valeur = c;
}

float Variable::calcul()
{
    return _valeur;
}



char Variable::getCsteV() {
    return _csteV;
}

float Variable::getValeur(){
    return _valeur;
}

void Variable::affichageClassique()
{
    return _csteV ;
}

void Variable::affichagePolonaiseInversee()
{
   return _csteV ;
}

std::string Variable::ToString() {
    string par1 = "(";
    string par2 = ")";
    string x;
    x += getCsteV();
    string y = std::to_string(getValeur());
    string msg = par1 + x + _symbol + y + par2;
    return msg;
}


#include "variable.h"
#include <iostream>

using namespace std;

Variable::Variable()
{
    _csteV = 'c';
    _valeur = 1;
    next = NULL;
}

Variable::Variable(char c)
{
    _csteV = c;
    _valeur = 1;
    next = NULL;
}

Variable::Variable(char c, float nb)
{
    _csteV = c;
    this->setValeur(nb);
    next = NULL;
}


float Variable::calcul()
{
    return _valeur;
}

void Variable::setValeur(float c)
{
    _valeur = c;
}

char Variable::getCsteV() {
    return _csteV;
}

float Variable::getValeur(){
    return _valeur;
}

void Variable::affichageClassique()
{
    cout << _csteV ;
}

void Variable::affichagePolonaiseInversee()
{
    cout << _csteV ;
}


std::string Variable::affichageClassiqueStr() {
    std::string str = std::string(&_csteV);
    return str;
}

std::string Variable::affichagePolonaiseInverseeStr() {
    std::string str = std::string(&_csteV);
    return str;
}

Expression* Variable::simplifier(){
    Variable* var = new Variable(_csteV, _valeur);
    return var;
}

bool Variable::isConstante(){
    return false;
}

std::string Variable::ToString() {
    string par1 = "(";
    string par2 = ")";
    string x;
    x += getCsteV();
    string y = std::to_string(getValeur());
    string msg = par1 + x + _symbol + y + par2;
    return msg;
   
}
