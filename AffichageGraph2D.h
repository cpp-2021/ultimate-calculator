#ifndef AFFICHAGEGRAPH2D_H
#define AFFICHAGEGRAPH2D_H

#include <QWidget>
#include <QtCharts>

class AffichageGraph2D
{
public:
    AffichageGraph2D(QWidget *parent);
    QLineSeries *creerCurve(/*Variable variable*/int a, int b);
    QChart *createGraph(QLineSeries *courbe, char *title, int xMin, int xMax, int yMin, int yMax);
};

#endif // AFFICHAGEGRAPH2D_H
