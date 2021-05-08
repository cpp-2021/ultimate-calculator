#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionload_triggered();

    void on_actionsave_triggered();

    void on_actionEnter_Expression_triggered();

    void on_actionPrint_Classical_Expression_triggered();

    void on_actionPrint_P_I_Expression_triggered();

    void on_actionPrint_Value_Expression_triggered();

    void on_actionGraphical_2D_Print_triggered();

    void on_actionGraphical_3D_Print_triggered();

    void on_actionSimplify_Expression_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
