#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#define OFFSET 5;

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //1) Init UI
    ui->setupUi(this);
    this->title = "TITLE";
    this->xMin = -100;
    this->xMax = 100;
    this->yMin = -100;
    this->yMax = 100;
    this->a = 5;
    this->b = 3;

    //2) Init btns & graphics view
    initBtns();
    initGraphics();
}



// BTNS //
void MainWindow::initBtns(){

    // XMIN
    QPushButton *btn_xmin_inf = findChild<QPushButton*>("xmin_inf");
    QPushButton *btn_xmin_sup = findChild<QPushButton*>("xmin_sup");
    connect(btn_xmin_inf, &QPushButton::released, this, &MainWindow::xminInf);
    connect(btn_xmin_sup, &QPushButton::released, this, &MainWindow::xminSup);

    // XMAX
    QPushButton *btn_xmax_inf = findChild<QPushButton*>("xmax_inf");
    QPushButton *btn_xmax_sup = findChild<QPushButton*>("xmax_sup");
    connect(btn_xmax_inf, &QPushButton::released, this, &MainWindow::xmaxInf);
    connect(btn_xmax_sup, &QPushButton::released, this, &MainWindow::xmaxSup);

    // YMIN
    QPushButton *btn_ymin_inf = findChild<QPushButton*>("ymin_inf");
    QPushButton *btn_ymin_sup = findChild<QPushButton*>("ymin_sup");
    connect(btn_ymin_inf, &QPushButton::released, this, &MainWindow::yminInf);
    connect(btn_ymin_sup, &QPushButton::released, this, &MainWindow::yminSup);

    // YMAX
    QPushButton *btn_ymax_inf = findChild<QPushButton*>("ymax_inf");
    QPushButton *btn_ymax_sup = findChild<QPushButton*>("ymax_sup");
    connect(btn_ymax_inf, &QPushButton::released, this, &MainWindow::ymaxInf);
    connect(btn_ymax_sup, &QPushButton::released, this, &MainWindow::ymaxSup);
}
void MainWindow::xminInf(){
    this->xMin -= OFFSET;
    initGraphics();
}
void MainWindow::xminSup(){
    this->xMin += OFFSET;
    initGraphics();
}
void MainWindow::yminInf(){
    this->yMin -= OFFSET;
    initGraphics();
}
void MainWindow::yminSup(){
    this->yMin += OFFSET;
    initGraphics();
}
void MainWindow::xmaxInf(){
    this->xMax -= OFFSET;
    initGraphics();
}
void MainWindow::xmaxSup(){
    this->xMax += OFFSET;
    initGraphics();
}
void MainWindow::ymaxInf(){
    this->yMax -= OFFSET;
    initGraphics();
}
void MainWindow::ymaxSup(){
    this->yMax += OFFSET;
    initGraphics();
}



// GRAPHICS //
void MainWindow::initGraphics(){
    QChartView *graphique = findChild<QChartView*>("graphics");

    QLineSeries *courbe = createCurve();
    QChart *graphe = createGraph(courbe);
    graphique->setChart(graphe);
}
QLineSeries* MainWindow::createCurve(){

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
QChart* MainWindow::createGraph(QLineSeries *courbe){

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



MainWindow::~MainWindow()
{
    delete ui;
}

