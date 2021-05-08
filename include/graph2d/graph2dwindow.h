#ifndef GRAPH2DWINDOW_H
#define GRAPH2DWINDOW_H

#include <QtWidgets>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class Graph2DWindow; }
QT_END_NAMESPACE

class Graph2DWindow: public QWidget
{
    Q_OBJECT

    public:
        Graph2DWindow(QWidget *parent = nullptr);
        void handleButton(int axis);
        void initBtns();
        void initGraphics();
        QLineSeries *createCurve();
        QChart *createGraph(QLineSeries *courbe);
        void xminInf();
        void xminSup();
        void yminInf();
        void yminSup();
        void xmaxInf();
        void xmaxSup();
        void ymaxInf();
        void ymaxSup();
        ~Graph2DWindow();

    private:
        Ui::Graph2DWindow *ui;
        int a; //TMP
        int b; //TMP
        float xMin;
        float xMax;
        float yMin;
        float yMax;
        char *title;
};

#endif // GRAPH2DWINDOW_H
