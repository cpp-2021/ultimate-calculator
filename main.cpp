#include <QApplication>

#include <iostream>

#include "include/Constante.h"

#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"
#include "include/Puissance.h"

#include "include/RootExpressionSingleton.h"

#include "include/mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Constante c(2.0f);
    cout << Puissance(&c,&c).calculer() << endl;

    MainWindow w;
    w.show();

    return a.exec();
}
