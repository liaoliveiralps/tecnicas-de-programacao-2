#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complex.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    a.set(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
    ui->lineEdit_3->setFocus();
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    ui->lineEdit_4->setFocus();
}

void MainWindow::on_lineEdit_4_returnPressed()
{
    b.set(ui->lineEdit_3->text().toInt(), ui->lineEdit_4->text().toInt());
    ui->pushButton->setFocus();
}

void MainWindow::on_pushButton_clicked()
{
    c = a + b;
    ui->lineEdit_5->setText(c.get());
    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_pressed()
{
    MainWindow::on_pushButton_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{
    c = a - b;
    ui->lineEdit_5->setText(c.get());
}

void MainWindow::on_pushButton_3_clicked()
{
    c = a * b;
    ui->lineEdit_5->setText(c.get());
}

void MainWindow::on_pushButton_4_clicked()
{
    c = a / b;
    ui->lineEdit_5->setText(c.get());
}

void MainWindow::on_pushButton_5_clicked()
{
    bool resp = a.operator==(b);
    if(resp == true)
        ui->lineEdit_5->setText("Iguais");
    else
        ui->lineEdit_5->setText("Diferentes");
}
