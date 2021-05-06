#include "Graph2D.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QPushButton>
#include "mainwindow.h"



Graph2D::Graph2D(/*Variable variable*/ int a, int b) {
    this->a = a;
    this->b = b;
}



QLineSeries* Graph2D::createCurve(){

    //1) Create curve
    QLineSeries *courbe = new QLineSeries();
    for(int x=-10; x<10; x++)
    {
        int y = a*x + b;
        *courbe << QPointF(x, y);
    }

    //2) Init legends
    courbe->setName(QString::fromUtf8(/*Expression name*/"EXPRESSION_NAME"));
    QPen pen(0x059605);
    pen.setWidth(3);
    pen.setStyle(Qt::DashLine);
    courbe->setPen(pen);

    return courbe;
}



QChart* Graph2D::createGraph(QLineSeries *courbe, char *title, MainWindow *parent){

    //1) Init graph & Add curve
    QChart *graph = new QChart();
    graph->addSeries(courbe);

    //2) Set settings
    graph->setTitle(title);
    //graphe->legend()->hide();
    graph->legend()->setAlignment(Qt::AlignBottom);
    graph->createDefaultAxes();
    graph->axes(Qt::Horizontal).first()->setRange(xMin, xMax);
    graph->axes(Qt::Vertical).first()->setRange(yMin, yMax);

    return graph;
}
