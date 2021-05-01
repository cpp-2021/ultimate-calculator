#ifndef LOADSAVE_H
#define LOADSAVE_H


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

#include <stack>
#include <vector>


#include "Expression.h"
#include "Constante.h"
#include "Operation.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"


void Save(Expression *E);
Expression *Load(std::string path);


#endif // LOADSAVE_H
