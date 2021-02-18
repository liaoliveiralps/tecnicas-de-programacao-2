#ifndef ITEM_H
#define ITEM_H
//#include "pedido.h"
#include "llde.h"
#include <QCoreApplication>
#include <QDateTime>
class Itens
{
protected:
    int codPedido;
    QString codItem;
    QString quantidade;
    QString precoUnitario;
    QString valorT;
    QString path = qApp->applicationFilePath();
    LLDE<Itens*> listaItem;
    Itens *ponteiroItem;
public:
    Itens();
    Itens(int codPedido, QString codItem, QString quantidade, QString precoUni);
    QString getCodItem()const{return codItem;}
    void setCodItem(int cod){codItem=cod;}
    int getCodPedido()const{return codPedido;}
    void setCodPedido(int cod){codPedido=cod;}
    QString getQuantidade(){return quantidade;}
    void setQuantidade(int qtde){quantidade=qtde;}
    QString getUnitario()const{return precoUnitario;}
    void setUnitario(QString preco){precoUnitario=preco;}
    int PrecoUni(int codProduto);
    int getValorTotal(int quantidade, int codProd);
    void cadastrar(int codPedido, int codItem, int quantidade);
    QString consultarItens(int codPedido);
    void removerItem(int codPedido);
};
class Pedido : public Itens
{
protected:
    int numeroPedido;
    QString status;
    QString data;
    float valorTotal;
    LLDE<Pedido*> listaPedido;
    Pedido *ponteiro;
public:
    Pedido();
    Pedido(int codPedido,QString status, QString data, float valorTotal,
           QString codItem, QString quantidadeItem, QString precoUniItem);

    int getNumeroPedido(){return numeroPedido;}
    void setNumeroPedido(int num);
    //void setNumero(int num);
    QString getStatus(){return status;}
    void setStatus(QString s){status=s;}
    QString getData(){return data;}
    void setData(QDateTime data){this->data=data.toString();}
    float getValorTotal(){return valorTotal;}
    void setValorTotal(float valor);

    void analisar(int codigoPedido, int codigoCliente, QString path);
    bool operator == (Pedido pedido)const;
    bool operator != (Pedido pedido)const;
    bool operator < (Pedido pedido)const;
    bool operator <= (Pedido pedido)const;
    bool operator > (Pedido pedido)const;
    bool operator >= (Pedido pedido)const;

};
#endif // ITEM_H
