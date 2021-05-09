#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "include/Expression.h"
#include <string>

void save(Expression *E, std::string path = "saved.txt");
Expression *load(std::string path = "saved.txt");

#endif // LOADSAVE_H
