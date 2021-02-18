#ifndef PERSISTIRPRODUTO_H
#define PERSISTIRPRODUTO_H
#include "llde.h"
#include "produto.h"
#include <QString>
#include <QStringList>
#include <fstream>
#include "persistirpedido.h"
class PersistirProduto
{
private:
    QString path;
    LLDE<Produto*> listaDeProdutos;
    Produto *ponteiro;
public:
    PersistirProduto();

    void setPath(const QString path){this->path = path;}

    void abrirArquivo();
    void atualizarArquivo();
    LLDE<Produto*> getListaDeProdutos(){return listaDeProdutos;}

    QString padronizarCodigo(QString codigo)const;
    QString precoComVirgula(QString preco)const;

    void cadastrarProduto(QString codigo, QString descricao, int quantidade, float preco);
    bool analisarProduto(QString codigo)const;
    QString listarProdutos()const;
    void excluirProdutos(QString codigo);
    Produto consultarProduto(QString codigo)const;
    float valorUnitario(QString codigo);
};


#endif // PERSISTIRPRODUTO_H
