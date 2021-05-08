#ifndef USER_INPUT_WINDOW_H
#define USER_INPUT_WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class UserInputWindow; }
QT_END_NAMESPACE

class UserInputWindow : public QWidget
{
    Q_OBJECT

public:
    UserInputWindow(QWidget *parent = nullptr);
    ~UserInputWindow();

private:
    Ui::UserInputWindow *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButton();
    void ClearButton();
    void AddVirgule();
};


#endif // USER_INPUT_WINDOW_H
