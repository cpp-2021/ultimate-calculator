// #include "mainwindow.h"

// #include <QApplication>

#include <iostream>
#include "include/Constante.h"
#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"
#include "include/RootExpressionSingleton.h"
#include <stack>
#include "string.h"

using namespace std;

int main()
{
    stack<Expression*> expr;
    char c[20];
    Constante *c1;
    Constante *c2;

    cout << "Entrer votre expression, taper p pour terminer." << endl;

    cin >> c;

    while (strcmp(c, "p")) {
        if (isdigit(c[0])) {
            Constante c1(stof(c));
            expr.push(&c1);
        } else {
            switch (c[0]) {
                case '/':
                    {
                        c1 = dynamic_cast<Constante *>(expr.top());
                        c2 = dynamic_cast<Constante *>(expr.top());
                        Division d(c1, c2);
                        expr.push(&d);
                        break;
                    }
                case '+':
                    {
                        c1 = dynamic_cast<Constante *>(expr.top());
                        c2 = dynamic_cast<Constante *>(expr.top());
                        Addition a(c1, c2);
                        expr.push(&a);
                        break;
                    }
                case '-':
                    {
                        c1 = dynamic_cast<Constante *>(expr.top());
                        c2 = dynamic_cast<Constante *>(expr.top());
                        Soustraction c(c1, c2);
                        expr.push(&c);
                        break;
                    }
                case '*':
                   {
                        c1 = dynamic_cast<Constante *>(expr.top());
                        c2 = dynamic_cast<Constante *>(expr.top());
                        Multiplication m(c1, c2);
                        expr.push(&m);
                        break;
                   }
                default:
                    cout << "Invalid operation.";
                    exit -1;
            }
        }
        cin >> c;
    }

    return 0;
}
