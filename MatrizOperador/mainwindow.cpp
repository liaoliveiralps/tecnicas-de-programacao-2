#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButtonCriarMatA_clicked()
{
    try {
        int linhas = ui->lineEditLinhasMatA->text().toInt();
        int colunas = ui->lineEditColunasMatA->text().toInt();
        matA = new lia::Matriz(linhas,colunas);
        for(int l=0; l < linhas ; l++){
            for(int c=0; c < colunas; c++){
                int elemento =  QInputDialog::getInt(this , "Leitura",
                                "Matriz A [ "+ QString::number(l) + ", "+
                                QString::number(c) + "] = ");
                matA->setElemento(elemento,l,c);
            }
        }
        ui->textEditSaidaMatA->setText(matA->getMatriz());

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }    catch(std::bad_alloc&){
        QMessageBox::information(this,"ERRO","Matriz A nao Criada");
    }
}

void MainWindow::on_pushButtonCriarMatB_clicked()
{
    try {
        int linhas = ui->lineEditLinhasMatB->text().toInt();
        int colunas = ui->lineEditColunasMatB->text().toInt();
        matB = new lia::Matriz(linhas,colunas);
        for(int l=0; l < linhas ; l++){
            for(int c=0; c < colunas; c++){
                int elemento =  QInputDialog::getInt(this , "Leitura",
                                "Matriz A [ "+ QString::number(l) + ", "+
                                QString::number(c) + "] = ");
                matB->setElemento(elemento,l,c);
            }
        }
        ui->textEditSaidaMatB->setText(matB->getMatriz());
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }catch(std::bad_alloc&){
        QMessageBox::information(this,"ERRO","Matriz B nao Criada");
    }
}

void MainWindow::on_pushButtonAdicionar_clicked()
{
    try {
        lia::Matriz *matAdicao = matA->operator+(matB);
        ui->textEditSaida->setText(matAdicao->getMatriz());
        delete matAdicao;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_clicked()
{
    try {
        lia::Matriz *matSubtracao = matA->operator-(matB);
        ui->textEditSaida->setText(matSubtracao->getMatriz());
        delete matSubtracao;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonMulti_clicked()
{
    try {
        lia::Matriz *matMulti = matA->operator*(matB);
        ui->textEditSaida->setText(matMulti->getMatriz());
        delete matMulti;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try {
        QString matTransposta = matA->transposta();
        ui->textEditSaida->setText(matTransposta);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonTranspostaB_clicked()
{
    try {
        QString matTransposta = matB->transposta();
        ui->textEditSaida->setText(matTransposta);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    try {
        int constante =  QInputDialog::getInt(this , "Leitura",
                                "Constante: ");
        QString matK = matA->multiPorConstante(constante);
        ui->textEditSaida->setText(matK);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonConstanteB_clicked()
{
    try {
        int constante =  QInputDialog::getInt(this , "Leitura",
                                "Constante: ");
        QString matK = matB->multiPorConstante(constante);
        ui->textEditSaida->setText(matK);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    try {
        //MATRIZ IGUAIS E DIFERNTES//
        bool igualdade = matA->igualdadeEDiferenca(matB);
        QString saida;
        if (igualdade==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemIgualdade = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(4,0,itemIgualdade);
        itemIgualdade = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(4,1,itemIgualdade);

        if(igualdade==false)
            saida="sim";
        else
            saida="não";
        QTableWidgetItem *itemDiferente = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(5,0,itemDiferente);
        itemDiferente = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(5,1,itemDiferente);

        //MATRIZ SIMETRICA//
        bool simetrica = matA->simetrica(matA);
        if (simetrica==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemSimetrica = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(2,0,itemSimetrica);

        simetrica = matB->simetrica(matB);
        if (simetrica==true)
            saida = "sim";
        else
            saida = "não";
        itemSimetrica = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(2,1,itemSimetrica);

        //TRIANGULAR SUPERIOR//
        bool superior = matA->triangularSuperior(matA);
        if (superior==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemSuperior = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(0,0,itemSuperior);

        superior = matB->triangularSuperior(matB);
        if (superior==true)
            saida = "sim";
        else
            saida = "não";
        itemSuperior = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(0,1,itemSuperior);

        //TRIANGULAR INFERIOR//
        bool inferior = matA->triangularInferior(matA);
        if(inferior==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemInferior = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(1,0,itemInferior);

        inferior = matB->triangularInferior(matA);
        if(inferior==true)
            saida = "sim";
        else
            saida = "não";
        itemInferior = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(1,1,itemInferior);

        //MATRIZ IDENTIDADE//
        bool identidade = matA->identidade(matA);
        if(identidade==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemIdentidade = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(3,0,itemIdentidade);

        identidade = matB->identidade(matA);
        if(identidade==true)
            saida = "sim";
        else
            saida = "não";
        itemIdentidade = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(3,1,itemIdentidade);

        //MATRIZ ORTOGONAL//
        bool ortogonal = matA->ortogonal(matA);
        if(ortogonal==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemOrtogonal = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(6,0,itemOrtogonal);

        ortogonal = matB->ortogonal(matB);
        if(ortogonal==true)
            saida = "sim";
        else
            saida = "não";
        itemOrtogonal = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(6,1,itemOrtogonal);
        //MATRIZ PERMUTAÇÃO//
        bool permuta = matA->permuta(matA);
        if(permuta==true)
            saida = "sim";
        else
            saida = "não";
        QTableWidgetItem *itemPermuta = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(7,0,itemPermuta);

        permuta = matB->permuta(matB);
        if(permuta==true)
            saida = "sim";
        else
            saida = "não";
        itemPermuta = new QTableWidgetItem(saida);
        ui->tableWidgetGrid->setItem(7,1,itemPermuta);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
