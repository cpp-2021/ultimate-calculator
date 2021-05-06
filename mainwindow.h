#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void min();
    QPushButton* btn_xMin;
    QPushButton* btn_xMax;
    QPushButton* btn_yMin;
    QPushButton* btn_yMax;
    QGraphicsView* graph;

private:
    Ui::MainWindow *ui;
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données
};
#endif // MAINWINDOW_H
