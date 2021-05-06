#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Graph2D.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //1) Init UI
    ui->setupUi(this);
    btn_xMin = findChild<QPushButton*>("btn_xMin");
    btn_xMax = findChild<QPushButton*>("btn_xMax");
    btn_yMin = findChild<QPushButton*>("btn_yMin");
    btn_yMax = findChild<QPushButton*>("btn_yMax");
    graph = findChild<QGraphicsView*>("graphics");
    connect(btn_xMin, &QPushButton::released, this, &MainWindow::min);

    QWidget *widget = new QWidget();
    QGridLayout *layout = new QGridLayout(widget);

    layout->addWidget(btn_xMin, 0, 0, 1, 1);
    layout->addWidget(btn_xMax, 0, 1, 1, 1);
    layout->addWidget(btn_yMin, 0, 2, 1, 1);
    layout->addWidget(btn_yMax, 0, 3, 1, 1);

    //2) Display graphics
   Graph2D *affichage = new Graph2D(-10, 2);
   QLineSeries *courbe = affichage->createCurve();
   QChart *graphe = affichage->createGraph(courbe, "TITLE", this);

   //3) Set graphique content (Chart View)
   QChartView *graphique = new QChartView(graphe);
   graphique->setRenderHint(QPainter::Antialiasing);
   setCentralWidget(graphique);
   resize(640, 480);
   layout->addWidget(graphique, 1, 0, 1, 1);


    setCentralWidget(widget);
    widget->setLayout(layout);
}
void MainWindow::min(){
    btn_xMin->setText("lol");
}
MainWindow::~MainWindow()
{
    delete ui;
}

