#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
#include <iostream>
using std::string;
class Produto
{
protected:
    int cod;
    string descricao;
    double preco;
    string tipoProduto;
public:
    Produto(int cod, string descricao, double preco, string tipo);
    int getCod(){return cod;}
    void setCod(int cod){this->cod=cod;}
    string getDescricao(){return descricao;}
    void setDescricao(string descricao){this->descricao=descricao;}
    double getPreco(){return preco;}
    void setPreco(double preco){this->preco=preco;}
    string getProd(){return tipoProduto;}
    void setProd(string prod){tipoProduto=prod;}
};

#endif // PRODUTO_H
