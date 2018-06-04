#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userSecondNum = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    ui->Plus->setCheckable(true);
    ui->Minus->setCheckable(true);
    ui->Multiply->setCheckable(true);
    ui->Divide->setCheckable(true);


    connect(ui->Button0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button9,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Sign,SIGNAL(released()),this,SLOT(Sign_pressed()));
    connect(ui->Plus,SIGNAL(released()),this,SLOT(binaryOperation_pressed()));
    connect(ui->Minus,SIGNAL(released()),this,SLOT(binaryOperation_pressed()));
    connect(ui->Multiply,SIGNAL(released()),this,SLOT(binaryOperation_pressed()));
    connect(ui->Divide,SIGNAL(released()),this,SLOT(binaryOperation_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;
    if ((ui->Plus->isChecked() || ui->Minus->isChecked() || ui->Multiply->isChecked() || ui->Divide->isChecked()) && (!userSecondNum))
    {
        labelNumber = (button->text()).toDouble();
        userSecondNum = true;
         newLabel = QString::number(labelNumber,'g',9);
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
             labelNumber = (ui->label->text() + button->text()).toDouble();
              newLabel = QString::number(labelNumber,'g',9);
        }

    }




    //Changes Label through button
    ui->label->setText(newLabel);
}

void MainWindow::on_Point_clicked()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::Sign_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    if(button->text() == "+/-")
    {
        double labelNumber;
        labelNumber = ui->label->text().toDouble();
        labelNumber *= -1;
        QString newLabel;
        newLabel = QString::number(labelNumber,'g',9);
        ui->label->setText(newLabel);

    }

}

void MainWindow::on_ButtonClear_released()
{
    ui->Plus->setChecked(false);
    ui->Minus->setChecked(false);
    ui->Multiply->setChecked(false);
    ui->Divide->setChecked(false);

    userSecondNum = false;

    ui->label->setText("0");
}

void MainWindow::on_Result_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if(ui->Plus->isChecked())
    {
       labelNumber = firstNum + secondNum ;
       newLabel = QString::number(labelNumber,'g',9);
       ui->label->setText(newLabel);
       ui->Plus->setChecked(false);
    }
    else if(ui->Minus->isChecked())
    {
        labelNumber = firstNum - secondNum ;
        newLabel = QString::number(labelNumber,'g',9);
        ui->label->setText(newLabel);
        ui->Minus->setChecked(false);
    }
    else if(ui->Multiply->isChecked())
    {
        labelNumber = firstNum * secondNum ;
        newLabel = QString::number(labelNumber,'g',9);
        ui->label->setText(newLabel);
        ui->Multiply->setChecked(false);
    }
    else if(ui->Divide->isChecked())
    {
        labelNumber = firstNum / secondNum ;
        newLabel = QString::number(labelNumber,'g',9);
        ui->label->setText(newLabel);
        ui->Divide->setChecked(false);
    }
    else
    {

    }

    userSecondNum = false;
}

void MainWindow::binaryOperation_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);

}

void MainWindow::on_Modulus_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    if(button->text() == "%")
    {
        double labelNumber;
        labelNumber = ui->label->text().toDouble();
        labelNumber /= 100;
        QString newLabel;
        newLabel = QString::number(labelNumber,'g',9);
        ui->label->setText(newLabel);

    }
}

void MainWindow::on_Del_released()
{

    QString newLabel;
    newLabel = ui->label->text();
    newLabel.chop(1);
    ui->label->setText(newLabel);
}
