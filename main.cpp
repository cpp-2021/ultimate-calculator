#include <QApplication>

#include <iostream>

#include "include/Constante.h"

#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"

#include "include/RootExpressionSingleton.h"

#include "include/graph2d/graph2dwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //Graph2DWindow w;
    //w.show();

    MainWindow w;
    w.show();

    return a.exec();
}
