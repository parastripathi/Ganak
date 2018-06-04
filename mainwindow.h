#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_Point_clicked();
    void Sign_pressed();
    void on_ButtonClear_released();
    void on_Result_released();
    void binaryOperation_pressed();
    void on_Modulus_pressed();
    void on_Del_released();
};

#endif // MAINWINDOW_H
