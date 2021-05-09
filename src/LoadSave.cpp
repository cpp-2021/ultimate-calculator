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


Expression * ParseVector(std::vector<std::string> tokens){
    std::stack<Expression *> expressionStack;
    for(auto s: tokens){
        if(s.at(0) == '('){

        }else if(s.at(0) == ')'){

        }else if(s == "+"){
            Expression *gauche = expressionStack.top();
            expressionStack.pop();
            Expression *droite = expressionStack.top();
            expressionStack.pop();
            Addition * add = new Addition(gauche, droite);
            expressionStack.push(add);
        }else if(s == "-"){
            Expression *gauche = expressionStack.top();
            expressionStack.pop();
            Expression *droite = expressionStack.top();
            expressionStack.pop();
            Soustraction * s = new Soustraction(gauche, droite);
            expressionStack.push(s);
        }else if(s == "*"){
            Expression *gauche = expressionStack.top();
            expressionStack.pop();
            Expression *droite = expressionStack.top();
            expressionStack.pop();
            Multiplication * m = new Multiplication(gauche, droite);
            expressionStack.push(m);
        }else if(s == "/"){
            Expression *gauche = expressionStack.top();
            expressionStack.pop();
            Expression *droite = expressionStack.top();
            expressionStack.pop();
            Division * d = new Division(gauche, droite);
            expressionStack.push(d);
        }else{
            float val = stof(s);
            Constante *con = new Constante(val);
            expressionStack.push(con);
        }
    }
    Expression *e = expressionStack.top();
    return e;
}
