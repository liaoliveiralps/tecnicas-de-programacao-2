#ifndef PRODUTO_H
#define PRODUTO_H
#include <QString>
#include "llde.h"

class Produto
{
private:
    QString codigo; // formato R0000
    QString descricao;
    float preco;
    int quantidade;
public:
    Produto();
    Produto(QString codigo);

    void setCodigo(QString codigo);
    QString getCodigo()const{return codigo;}

    void setDescricao(QString descricao){this->descricao = descricao;}
    QString getDescricao(){return descricao;}

    void setPreco(float preco);
    float getPreco()const{return preco;}

    void setQuantidade(int quantidade);
    int getQuantidade()const{return quantidade;}

    bool operator == (Produto& produto)const;
    bool operator != (Produto& produto)const;
    bool operator < (Produto& produto)const;
    bool operator <= (Produto& produto)const;
    bool operator > (Produto& produto)const;
    bool operator >= (Produto& produto)const;
};
#endif // PRODUTO_H


