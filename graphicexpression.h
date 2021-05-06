#ifndef GRAPHICEXPRESSION_H
#define GRAPHICEXPRESSION_H

#include <QtWidgets>
#include <QtCharts>

class GraphicExpression : public QMainWindow
{
    Q_OBJECT

private:
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données

public:
    GraphicExpression(QWidget *parent = 0);
    ~GraphicExpression();
};

#endif // IHMGRAPHIQUE_H
