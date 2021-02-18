#ifndef PERSISTIRPEDIDO_H
#define PERSISTIRPEDIDO_H
//#include "pedido.h"
#include <string>
#include "item.h"
#include<string>
#include<QString>
#include<typeinfo>
using namespace std;
class PersistirPedido
{
private:
    QString path;
    LLDE<Pedido*> listaPed;
    Pedido *ponteiro;
public:
    PersistirPedido();
    void setPath(const QString path){this->path = path;}
    void setLista();
    LLDE<Pedido*> getListaDePedidos(){return listaPed;}
    void cadastrarPedido(int codPedido,QString status, QString data, float valorTotal,
                         QString codItem, QString quantidadeItem, QString precoUniItem);
    bool analisarPedido(int codigo);
    QString consultarPedido(int codigo);
    void excluirPedidos(int codigo);
    QString listarPedidos();
    void persistir(int i);

    QString getPath()const{return path;}

};
#endif // PERSISTIRPEDIDO_H
