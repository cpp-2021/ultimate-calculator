#include "include/LoadSave.h"

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
