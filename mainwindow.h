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
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        int a; //TMP
        int b; //TMP
        int xMin;
        int xMax;
        int yMin;
        int yMax;
        char *title;
};
#endif // MAINWINDOW_H
