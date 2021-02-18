#include "item.h"
#include "produto.h"
#include "persistirproduto.h"
#include "persistircliente.h"
#include "llse.h"
Itens::Itens():
    codPedido(0),
    codItem(""),
    quantidade(""),
    precoUnitario(""),
    valorT(""),
    ponteiroItem(nullptr)
{

}
Itens::Itens(int codPedido, QString codItem, QString quantidade, QString precoUni):
    codPedido(codPedido),
    codItem(codItem),
    quantidade(quantidade),
    precoUnitario(precoUni)
{

}
int Itens::getValorTotal(int quantidade, int codProd){
    float valor;
    valor = quantidade*PrecoUni(codProd);
    return valor;
}
int Itens::PrecoUni(int codProduto){
    PersistirProduto teste;
    float valorUnitario=0;
    teste.setPath(path);
    teste.abrirArquivo();
    QString codigo = teste.padronizarCodigo(QString::number(codProduto));
    if(teste.analisarProduto(QString::number(codProduto))==true){
        for(int i=0; i<teste.getListaDeProdutos().getQuantidade(); i++){
            if(teste.getListaDeProdutos()[i]->getCodigo() == codigo){
                valorUnitario = teste.getListaDeProdutos()[i]->getPreco();
                return valorUnitario;
                break;
            }
        }
        return valorUnitario;
    }
    else
        throw QString("Produto não cadastrado");
}
void Itens::cadastrar(int codPedido, int codProd, int quantidade){
    setCodItem(codProd);
    setCodPedido(codPedido);
    setQuantidade(quantidade);
    PersistirProduto aux;
    aux.setPath(path);
    aux.abrirArquivo();
    if(quantidade<=0) throw QString("Quantidade inválida");
    float valor = PrecoUni(codProd);
    ponteiroItem = new Itens(codPedido, QString::number(codProd), QString::number(quantidade), QString::number(valor));
    listaItem.inserirInicio(ponteiroItem);
}
QString Itens::consultarItens(int codPedido){
    int aux=0;
    QString saida;
    while(aux!=listaItem.getQuantidade()){
        if(listaItem[aux]->getCodPedido()==codPedido){
            saida += "\nCódigo do item: " + listaItem[aux]->getCodItem()
                     + "\nQuantidade: " + listaItem[aux]->getQuantidade()
                     + "\nValor Unitário: R$" + QString::number(PrecoUni(listaItem[aux]->getCodItem().toFloat()));
        }
        aux++;
    }
    return saida;
}
void Itens::removerItem(int codPedido){
    if(listaItem.estaVazio()) throw QString("Não há itens");
    int posicao=0;
    for(int i=0;i<listaItem.getQuantidade();i++){
        if(listaItem[i]->getCodPedido()==QString::number(codPedido)){
            posicao=i;
            listaItem.retirarNaPosicao(posicao);
            break;
        }
    }
}

Pedido::Pedido():
    numeroPedido(0),
    status(""),
    valorTotal(0)
{

}
Pedido::Pedido(int codPedido,QString status, QString data, float valorTotal,
               QString codItem, QString quantidadeItem, QString precoUniItem):
    Itens(codPedido, codItem, quantidadeItem, precoUniItem),
    numeroPedido(codPedido),
    status(status),
    data(data),
    valorTotal(valorTotal)
{

}
void Pedido::setNumeroPedido(int num){
    if(num<0) throw QString("Número de pedido inválido");
    numeroPedido=num;
}
void Pedido::setValorTotal(float valor){
    if(valor<0) throw QString("Valor total inválido");
    valorTotal=valor;
}
bool Pedido::operator == (Pedido pedido) const{
    if(this->numeroPedido == pedido.getNumeroPedido())
        return true;
    return false;
}
bool Pedido::operator != (Pedido pedido) const{
    if(this->numeroPedido != pedido.getNumeroPedido())
        return false;
    return true;
}
bool Pedido::operator < (Pedido pedido) const{
    if(this->numeroPedido < pedido.getNumeroPedido())
        return true;
    return false;
}
bool Pedido::operator <= (Pedido pedido) const{
    if(this->numeroPedido <= pedido.getNumeroPedido())
        return true;
    return false;
}
bool Pedido::operator > (Pedido pedido) const{
    if(this->numeroPedido > pedido.getNumeroPedido())
        return true;
    return false;
}
bool Pedido::operator >= (Pedido pedido) const{
    if(this->numeroPedido >= pedido.getNumeroPedido())
        return true;
    return false;
}

void Pedido::analisar(int codigoPedido, int codigoCliente, QString path){
    PersistirPedido aux;
    aux.setPath(path);
    if(aux.analisarPedido(codigoPedido)==true) throw QString("Pedido já existente");
    PersistirCliente p;
    p.setPath(path);
    if(p.analisaPessoa(codigoCliente)==false) throw QString("Cliente não existe");

}
