#include "persistirproduto.h"
PersistirProduto::PersistirProduto():
    path(""),
    listaDeProdutos()
{
}
void PersistirProduto::abrirArquivo(){
    //CRIANDO O CAMINHO DO ARQUIVO
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/produtos.csv";
    std::ifstream arquivoi;
    arquivoi.open(local.toStdString());
    if(!arquivoi.is_open()){
        //CRIAR O ARQUIVO SE ELE NÃO EXISTE
        std::ofstream arquivoo;
        arquivoo.open(local.toStdString());
        if(!arquivoo.is_open())
            throw QString("Erro ao criar arquivo - ANA");
    }
    else{
        //Jogando dados na lista
        std::string linha;
        std::getline(arquivoi,linha);
        while(!arquivoi.fail()){
            if(linha[0]=='R'){
                QStringList leia = QString::fromStdString(linha).split(";");
                QString codigo = "", descricao = "";
                int quantidade = 0;
                float preco = 0;
                codigo = leia[0];
                descricao = leia[1];
                preco = leia[2].toFloat();
                quantidade = leia[3].toInt();
                cadastrarProduto(codigo, descricao, quantidade, preco);
            }
            std::getline(arquivoi,linha);
    }
    }
    arquivoi.close();
}
void PersistirProduto::atualizarArquivo(){
    QString caminho="";
    int tamanho = path.size()-28;
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    QString local = caminho + "/produtos.csv";
    std::ofstream arquivoo;
    arquivoo.open(local.toStdString());
    if(!arquivoo.is_open())
        throw QString("Erro ao abrir o arquivo - ANA");
    arquivoo.clear();
    QString codigo = "",descricao = "", preco = "", quantidade = "";
    QString saida = "Codigo;Descricao;Preco;Quantidade";
    arquivoo<<saida.toStdString();
    tamanho = listaDeProdutos.getQuantidade();
    for(int i = 0;i<tamanho;i++){
        codigo = listaDeProdutos[i]->getCodigo();
        descricao = listaDeProdutos[i]->getDescricao();
        preco = QString::number(listaDeProdutos[i]->getPreco());
        quantidade = QString::number(listaDeProdutos[i]->getQuantidade());
        saida.clear();
        saida += codigo + ";" + descricao + ";" + preco + ";" + quantidade;
        arquivoo<<"\n"<<saida.toStdString();
        codigo.clear();
        descricao.clear();
        preco.clear();
        quantidade.clear();
    }
    arquivoo.close();
}
void PersistirProduto::cadastrarProduto(QString codigo, QString descricao, int quantidade, float preco){
    ponteiro = new Produto();
    codigo = padronizarCodigo(codigo);
    ponteiro->setPreco(preco);
    ponteiro->setCodigo(codigo);
    ponteiro->setDescricao(descricao);
    ponteiro->setQuantidade(quantidade);
    listaDeProdutos.inserirOrdenado(ponteiro);
}
bool PersistirProduto::analisarProduto(QString codigo)const{
    codigo = padronizarCodigo(codigo);
    for(int i=0;i<listaDeProdutos.getQuantidade();i++){
        if(listaDeProdutos[i]->getCodigo()==codigo){
            return true;//produto já existe
        }
    }
    return false;
}
QString PersistirProduto::listarProdutos()const{
    QString saida = "";
    if(listaDeProdutos.estaVazio())
        throw QString("Não existem produtos cadastrados");
    PersistirProduto aux;
    aux.setPath(path);
    aux.abrirArquivo();
    for(int i=0;i<listaDeProdutos.getQuantidade();i++){
        saida += listaDeProdutos[i]->getCodigo() + "|"
               + listaDeProdutos[i]->getDescricao() + "|"
               + QString::number(listaDeProdutos[i]->getQuantidade()) + "|"
               + QString::number(listaDeProdutos[i]->getPreco()) + "-";
    }
    return saida;
}
Produto PersistirProduto::consultarProduto(QString codigo) const{
    if(listaDeProdutos.estaVazio()){
        throw QString("Não existem elementos para consultar");
    }
    codigo = padronizarCodigo(codigo);
    if(analisarProduto(codigo)==false){
        throw QString("Produto não existe");
    }
    Produto produto;
    int i;
    for(i=0;i<listaDeProdutos.getQuantidade();i++){
        if(listaDeProdutos[i]->getCodigo()==codigo){
            produto.setCodigo(listaDeProdutos[i]->getCodigo());
            produto.setPreco(listaDeProdutos[i]->getPreco());
            produto.setDescricao(listaDeProdutos[i]->getDescricao());
            produto.setQuantidade(listaDeProdutos[i]->getQuantidade());
        }
    }
    return produto;
}
void PersistirProduto::excluirProdutos(QString codigo){
    if(listaDeProdutos.estaVazio()){
        throw QString("Sem produtos para excluir");
    }
    if(codigo[0]=='R'){
        codigo.remove(0,1);
    }
    PersistirPedido aux;
    aux.setPath(path);
    aux.setLista();
    bool temNoPedido = aux.analisarPedido(codigo.toInt());
    if(temNoPedido == true){
        throw QString("Existem pedidos em andamento com este produto");
    }
    codigo = padronizarCodigo(codigo);
    for(int i=0;i<listaDeProdutos.getQuantidade();i++){
        if(listaDeProdutos[i]->getCodigo()==codigo){
            listaDeProdutos.retirarNaPosicao(i);
        }
    }
}

QString PersistirProduto::padronizarCodigo(QString codigo)const{
    //Padronizando no formado R0000
    int cont = codigo.size();
    if(codigo[0]=="R" && cont==5){
        return codigo;
    }
    if(codigo[0]=="R" && cont!=5){
        throw QString("Código no formato inválido\nFormato válido: R0000 ou apenas números");
    }
    if(cont!=5){
        QString padronizando = codigo;
        int zeros = 4-codigo.size();
        codigo.clear();
        codigo+="R";
        while(zeros--){
            codigo+="0";
        }
        for(int i=0;i<cont;i++){
            codigo+=padronizando[i];
        }
    }
    return codigo;
}
QString PersistirProduto::precoComVirgula(QString preco)const{
    //Ver se o preco está com , ou .
    int posi = preco.lastIndexOf(",");
    if(posi!=-1){
        preco.replace(posi,1,".");
    }
    return preco;
}
float PersistirProduto::valorUnitario(QString codigo){
    float preco=0;
    codigo = padronizarCodigo(codigo);
    if(listaDeProdutos.estaVazio())
        throw QString("Não existem produtos cadastrados");
    PersistirProduto aux;
    aux.setPath(path);
    aux.abrirArquivo();
    for(int i=0;i<listaDeProdutos.getQuantidade();i++){
        if(listaDeProdutos[i]->getCodigo()==codigo)
            preco = listaDeProdutos[i]->getPreco();
    }
    return preco;
}
