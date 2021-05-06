#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AffichageGraph2D.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //1) Init UI
    ui->setupUi(this);

    //2) Display graphics
    AffichageGraph2D *affichage = new AffichageGraph2D(parent);
    courbe = affichage->createCurve(-10, 2);
    graphe = affichage->createGraph(courbe, "TITLE", -10, 0, 0, 10);

    //3) Set graphique content (Chart View)
    graphique = new QChartView(graphe);
    graphique->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(graphique);
    resize(640, 480);
}

MainWindow::~MainWindow()
{
    delete ui;
}

