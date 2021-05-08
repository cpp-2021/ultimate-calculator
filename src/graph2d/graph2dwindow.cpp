#include "include/graph2d/graph2dwindow.h"
#include "ui_graph2dwindow.h"
#include <iostream>

#define OFFSET 5;

using namespace std;

Graph2DWindow::Graph2DWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Graph2DWindow)
{
    //1) Init UI
    this->title = "TITLE";
    this->xMin = -10;
    this->xMax = 10;
    this->yMin = -10;
    this->yMax = 10;
    this->a = 5;
    this->b = 3;

    ui->setupUi(this);

    //2) Init btns & graphics view
    initBtns();
    initGraphics();
}


// BTNS //
void Graph2DWindow::initBtns(){

    // XMIN
    QPushButton *btn_xmin_inf = findChild<QPushButton*>("xmin_inf");
    QPushButton *btn_xmin_sup = findChild<QPushButton*>("xmin_sup");
    connect(btn_xmin_inf, &QPushButton::released, this, &Graph2DWindow::xminInf);
    connect(btn_xmin_sup, &QPushButton::released, this, &Graph2DWindow::xminSup);

    // XMAX
    QPushButton *btn_xmax_inf = findChild<QPushButton*>("xmax_inf");
    QPushButton *btn_xmax_sup = findChild<QPushButton*>("xmax_sup");
    connect(btn_xmax_inf, &QPushButton::released, this, &Graph2DWindow::xmaxInf);
    connect(btn_xmax_sup, &QPushButton::released, this, &Graph2DWindow::xmaxSup);

    // YMIN
    QPushButton *btn_ymin_inf = findChild<QPushButton*>("ymin_inf");
    QPushButton *btn_ymin_sup = findChild<QPushButton*>("ymin_sup");
    connect(btn_ymin_inf, &QPushButton::released, this, &Graph2DWindow::yminInf);
    connect(btn_ymin_sup, &QPushButton::released, this, &Graph2DWindow::yminSup);

    // YMAX
    QPushButton *btn_ymax_inf = findChild<QPushButton*>("ymax_inf");
    QPushButton *btn_ymax_sup = findChild<QPushButton*>("ymax_sup");
    connect(btn_ymax_inf, &QPushButton::released, this, &Graph2DWindow::ymaxInf);
    connect(btn_ymax_sup, &QPushButton::released, this, &Graph2DWindow::ymaxSup);
}
void Graph2DWindow::xminInf(){
    this->xMin -= OFFSET;
    initGraphics();
}
void Graph2DWindow::xminSup(){
    this->xMin += OFFSET;
    initGraphics();
}
void Graph2DWindow::yminInf(){
    this->yMin -= OFFSET;
    initGraphics();
}
void Graph2DWindow::yminSup(){
    this->yMin += OFFSET;
    initGraphics();
}
void Graph2DWindow::xmaxInf(){
    this->xMax -= OFFSET;
    initGraphics();
}
void Graph2DWindow::xmaxSup(){
    this->xMax += OFFSET;
    initGraphics();
}
void Graph2DWindow::ymaxInf(){
    this->yMax -= OFFSET;
    initGraphics();
}
void Graph2DWindow::ymaxSup(){
    this->yMax += OFFSET;
    initGraphics();
}



// GRAPHICS //
void Graph2DWindow::initGraphics(){
    QChartView *graphique = findChild<QChartView*>("graphics");

    QLineSeries *courbe = createCurve();
    QChart *graphe = createGraph(courbe);
    graphique->setChart(graphe);
}
QLineSeries* Graph2DWindow::createCurve(){

    //1) Create curve
    QLineSeries *courbe = new QLineSeries();
    for(float x=xMin; x<xMax; x+=0.1f)
    {
        float y = x*x;
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
QChart* Graph2DWindow::createGraph(QLineSeries *courbe){

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



Graph2DWindow::~Graph2DWindow()
{
    delete ui;
}
