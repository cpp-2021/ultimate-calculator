#include "include/LoadSave.h"
#include "include/Expression.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

#include <stack>
#include <vector>

void save(Expression *E, std::string path){
    std::ofstream savefile(path, std::ofstream::out);
    savefile << E->toStringNpi();
    savefile.close();
    return;
}

/* [Equipe integration] Ne compile pas - la methode ParseVector n'existe pas */
Expression *load(std::string path){
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
               //e = ParseVector(tokens);       /* [Equipe integration] Methode qui n'existe pas */
               e = nullptr;                     /* [Equipe integration] Ajout pour renvoyer quelquechose */

               std::cout << e;
             }
             myfile.close();
     }
     else std::cout << "Unable to open file";
     return e;
}
