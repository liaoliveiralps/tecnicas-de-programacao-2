#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cubo.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonResult_clicked()
{
    lia::Cubo c;
    float aresta = ui->lineEditAresta->text().toFloat();
    c.setAresta(aresta);
    QString saida;
    saida += "Aresta: " + QString::number(c.getAresta());
    saida += "\nArea total: " + QString::number(c.area(aresta));
    saida += "\nVolume: " + QString::number(c.volume(aresta));
    ui->textEdit->setText(saida);
}
