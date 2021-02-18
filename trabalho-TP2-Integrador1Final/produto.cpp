#include "produto.h"
Produto::Produto():
    codigo(""),
    descricao(""),
    preco(0),
    quantidade(0)
{
}
Produto::Produto(QString codigo):
    codigo(codigo),
    descricao(""),
    preco(0),
    quantidade(0)
{
}
void Produto::setCodigo(QString codigo){
    if(codigo.length()>5)
        throw QString("Código fora do intervalo válido");
    this->codigo = codigo;
}
void Produto::setPreco(float preco){
    if(preco<0)
        throw QString("Preco invalido");
    this->preco = preco;
}
void Produto::setQuantidade(int quantidade){
    if(quantidade<0)
        throw QString("Quantidade invalida");
    this->quantidade = quantidade;
}
bool Produto::operator == (Produto& produto) const{
    if(this->codigo == produto.getCodigo())
        return true;
    return false;
}
bool Produto::operator != (Produto& produto) const{
    if(this->codigo != produto.getCodigo())
        return false;
    return true;
}
bool Produto::operator < (Produto& produto) const{
    if(this->codigo < produto.getCodigo())
        return false;
    return true;
}
bool Produto::operator <= (Produto& produto) const{
    if(this->codigo <= produto.getCodigo())
        return false;
    return true;
}
bool Produto::operator > (Produto& produto) const{
    if(this->codigo > produto.getCodigo())
        return true;
    return false;
}
bool Produto::operator >= (Produto& produto) const{
    if(this->codigo >= produto.getCodigo())
        return true;
    return false;
}
