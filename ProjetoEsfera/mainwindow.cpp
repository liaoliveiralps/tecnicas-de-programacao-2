#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <esfera.h>
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


void MainWindow::on_pushButtonExe_clicked()
{
    lia::Esfera e;
    float raio = ui->lineEditRaio->text().toFloat();
    e.setRaio(raio);
    QString saida;
    saida = "Raio: " + QString::number(e.getRaio());
    saida += "\nArea: " + QString::number(e.area(raio));
    saida += "\nVolume: " + QString::number(e.volume(raio));

    ui->textEditResult->setText(saida);
}

void MainWindow::on_lineEditRaio_returnPressed()
{
    ui->pushButtonExe->click();
}
