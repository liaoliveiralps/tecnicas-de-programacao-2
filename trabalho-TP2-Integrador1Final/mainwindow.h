#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"persistircliente.h"
#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include "llde.h"
#include "produto.h"
#include "persistirproduto.h"
#include "item.h"
#include "persistirpedido.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool validarProduto(QString codigo)const;
    QString padronizarCodigo(QString codigo)const;
    QString precoComVirgula(QString preco)const;

private slots:
    void on_pushButtonListar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonCadastrarNovo_clicked();

    void on_pushButtonConsultar_clicked();

    //Erick
    void on_pushButtonRegistrarCliente_clicked();




    void on_pushButtonRetirarCliente_clicked();

    void on_pushButtonListarClientes_clicked();
    void on_pushButtonConsultar_2_clicked();

    void on_lineEditCodigoCliente_returnPressed();

    void on_lineEditCpf_Cnpj_2_returnPressed();

    void on_lineEditNome_Razao_Social_2_returnPressed();

    void on_lineEditCelular_Nome_Contato_2_returnPressed();

    void on_lineEditTelefone_2_returnPressed();

    void on_lineEditEmail_2_returnPressed();

    void on_lineEditLogradouro_2_returnPressed();

    void on_lineEditEstado_2_returnPressed();

    void on_lineEditCidade_2_returnPressed();

    void on_lineEditSetor_2_returnPressed();

    void on_pushButtonCadastrarItem_clicked();

    void on_pushButtonRemover_clicked();

    void on_pushButtonConsultar_3_clicked();

    void on_pushButtonListar_2_clicked();


private:
    Ui::MainWindow *ui;
    QString path;
    PersistirProduto eng;

    PersistirCliente *a=new PersistirCliente;
    PersistirPedido *persistirP=new PersistirPedido;
    int v=0,vl=0;
};

#endif // MAINWINDOW_H
