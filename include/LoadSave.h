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

void Save(Expression *E){
    std::ofstream savefile("saved.txt", std::ofstream::out);
    savefile << E->getStringNpi();
    savefile.close();
    return;
}

Expression *Load(std::string path){
    std::string line;
    std::ifstream myfile (path);
    Expression *e;
     if (myfile.is_open())
     {
         while ( getline (myfile,line) )
             {
               std::cout << line << '\n';
               std::istringstream iss(line);
               std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                         std::istream_iterator<std::string>{}};
               e = ParseVector(tokens);
               std::cout << e;
             }
             myfile.close();
     }
     else std::cout << "Unable to open file";
     return e;
}

#endif // LOADSAVE_H
