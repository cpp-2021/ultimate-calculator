#ifndef GRAPH2D_H
#define GRAPH2D_H

#include <QWidget>
#include <QtCharts>
#include <mainwindow.h>

class Graph2D
{
    private:
        int a; //TMP
        int b; //TMP
        int xMin;
        int xMax;
        int yMin;
        int yMax;

    public:
        Graph2D(/*Variable variable*/int a, int b);
        QLineSeries *createCurve();
        QChart *createGraph(QLineSeries *courbe, char *title, MainWindow *parent);
        void affiche(QWidget *mainWindow, QMainWindow ui);
};

#endif // GRAPH2D_H
