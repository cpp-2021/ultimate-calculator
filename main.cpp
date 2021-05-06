#include "mainwindow.h"

#include <QApplication>

#include <iostream>

#include "include/Constante.h"

#include "include/Addition.h"
#include "include/Soustraction.h"
#include "include/Division.h"
#include "include/Multiplication.h"

#include "include/RootExpressionSingleton.h"

using namespace std;

int main(int argc, char *argv[])
{
       QApplication a(argc, argv);
       MainWindow w;
       w.show();
       return a.exec();
}
