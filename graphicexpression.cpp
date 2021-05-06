#include "graphicexpression.h"


GraphicExpression::GraphicExpression(QWidget *parent)
    : QMainWindow(parent)
{
    /*// Les données
    courbe = new QLineSeries();

    // Technique n°2
    // exemple avec un QValueAxis
    //courbe << QPointF(1, 21.5) << QPointF(2, 21.7) << QPointF(3, 22.6) << QPointF(4, 20.7) << QPointF(5, 19.6) << QPointF(6, 21.7) << QPointF(7, 21.5) << QPointF(8, 23.5)<< QPointF(9, 25.5)<< QPointF(10, 26.1);

    courbe->setName(QString::fromUtf8("Courbe"));
    QPen pen(0x059605);
    pen.setWidth(3);
    pen.setStyle(Qt::DashLine);
    courbe->setPen(pen);

    // Le graphe
    graphe = new QChart();
    graphe->addSeries(courbe);
    graphe->setTitle("Graphe 2D représentant une expression");
    // Légende
    //graphe->legend()->hide();
    graphe->legend()->setAlignment(Qt::AlignBottom);

    // Les axes
    // Par défaut
    graphe->createDefaultAxes();
    graphe->axes(Qt::Horizontal).first()->setRange(-10, -10);
    graphe->axes(Qt::Vertical).first()->setRange(0, 10);

    // Le widget
    graphique = new QChartView(graphe);
    graphique->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(graphique);
    resize(640, 480);*/
}

GraphicExpression::~GraphicExpression()
{

}

