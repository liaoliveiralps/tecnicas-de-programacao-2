#include "persistirpedido.h"
#include<fstream>
#include<string>
PersistirPedido::PersistirPedido():
    path(""),
    listaPed()
{

}
void PersistirPedido::setLista(){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Pedidos.csv";
    std::ifstream arquivoc;
    string linha1;
    arquivoc.open(local.toStdString());
    if(!arquivoc.is_open())
        throw QString("Erro ao criar arquivo");
    string linha;
    //Pega pedidos no arquivo e joga na lista ordenada
    int chave=0, chave2=0;
    QString codPedido, status, data, valorTotal,
            codItem, quantidadeItem, precoUniItem;
    while (!arquivoc.eof()) {
        getline(arquivoc,linha);
        string::iterator tp2;
        //pega o codigo do pedido
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                codPedido+=*tp2;
            }
            if(*tp2=='P'&& *(tp2+1)!='o'){
                chave=1;
            }
        }
        getline(arquivoc,linha);
        tp2=linha.begin();
        //pega o status
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                status+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        //pega a data
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                data+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        //pega o valor total
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                valorTotal+=*tp2;
            }
            if(*tp2=='$'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        //pega o cod do Item
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                codItem+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        //pega a quantidade
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                quantidadeItem+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        //pega o preco unitario
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                precoUniItem+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        if(!codPedido.isEmpty()){
            ponteiro = new Pedido(codPedido.toInt(), status, data, valorTotal.toFloat(),
                                       codItem, quantidadeItem, precoUniItem);
            listaPed.inserirOrdenado(ponteiro);
        }
        linha.clear();
        codPedido.clear();
        status.clear();
        valorTotal.clear();
        codItem.clear();
        quantidadeItem.clear();
        precoUniItem.clear();
        chave=0;
    }
    arquivoc.close();
}
void PersistirPedido::cadastrarPedido(int codPedido,QString status, QString data, float valorTotal,
                                      QString codItem, QString quantidadeItem, QString precoUniItem){
    status = "aberto";
    QDateTime dataAux;
    data = dataAux.currentDateTime().toString();
    Pedido aux;
    ponteiro = new Pedido(codPedido, status, data, valorTotal,
                          codItem, quantidadeItem, precoUniItem);
    listaPed.inserirOrdenado(ponteiro);
}
bool PersistirPedido::analisarPedido(int codigo){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Pedidos.csv";
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    int ok=0;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='P'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            //throw QString::number(hlp11);
            if(codigo==hlp11){
                ok=1;
            }
        }
        linha.clear();
    }
    if(ok==0){
        return false;//pedido não existe
    }
    else
        return true;
}
QString PersistirPedido::consultarPedido(int codigo){
    if(listaPed.estaVazio()) throw QString("Não há pedidos");
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Pedidos.csv";
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    int ok=0;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='P'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            if(codigo==hlp11){
                ok=1;
            }
        }
        linha.clear();
    }
    if(ok==0){
        throw QString("Pedido não existe");
    }
    QString saida;
    int b=0;
    for(int v=0;v<listaPed.getQuantidade();v++){
        if(listaPed[v]->getNumeroPedido()==codigo){
            b=v;
            v=listaPed.getQuantidade();
        }
    }
    ponteiro=listaPed[b];
    if(typeid (*ponteiro)==typeid (Pedido)){
        saida+= "P"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getNumeroPedido())+"|"+"\n"+
                "Status: "+dynamic_cast<Pedido*>(ponteiro)->getStatus()+"|"+"\n"+
                "Data: "+dynamic_cast<Pedido*>(ponteiro)->getData()+"|"+"\n"+
                "Valor Total: R$"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getValorTotal())+"|"+"\n"+
                "Item - código: "+dynamic_cast<Pedido*>(ponteiro)->getCodItem()+"|"+"\n"+
                "Quantidade: "+dynamic_cast<Pedido*>(ponteiro)->getQuantidade()+"|"+"\n"+
                "Preço Unitario: "+dynamic_cast<Pedido*>(ponteiro)->getUnitario();
    }
    arquivoco.close();
    return saida;
}
void PersistirPedido::excluirPedidos(int codigo){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Pedidos.csv";
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    int ok=0;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='P'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            if(codigo==hlp11){
                ok=1;
            }
        }
        linha.clear();
    }
    if(ok==0){
        throw QString("Cliente não existe");
    }
    int b=0;
    for(int v=0;v<listaPed.getQuantidade();v++){
        if(listaPed[v]->getNumeroPedido()==codigo){
            b=v;
            v=listaPed.getQuantidade();
        }
    }
    arquivoco.close();
    listaPed.retirarNaPosicao(b);
}
QString PersistirPedido::listarPedidos(){
    QString saida;
    if(listaPed.estaVazio()) throw QString("Não há pedidos");
    for(int v=0;v<listaPed.getQuantidade();v++){
        ponteiro=listaPed[v];
        if(typeid (*ponteiro)==typeid (Pedido)){
            //throw QString::number(ponteiro->getValorTotal());
            saida+= "P"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getNumeroPedido())+"|"+"\n"+
                    "Status: "+dynamic_cast<Pedido*>(ponteiro)->getStatus()+"|"+"\n"+
                    "Data:"+dynamic_cast<Pedido*>(ponteiro)->getData()+"|"+"\n"+
                    "Valor Total:R$"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getValorTotal())+"|"+"\n"+
                    "Item - código: \n"+dynamic_cast<Pedido*>(ponteiro)->getCodItem()+"|"+"\n"+
                    "Quantidade: \n"+dynamic_cast<Pedido*>(ponteiro)->getQuantidade()+"|"+"\n"+
                    "Preço Unitario: \n"+dynamic_cast<Pedido*>(ponteiro)->getUnitario()+"|"+"\n\n";
        }
    }
    return saida;
}
void PersistirPedido::persistir(int i){
    if(i==1){
        QString caminho="";
        int tamanho = path.size()-28;//-28 = nome do arquivo executável
        for(int i=0;i<tamanho;i++)
                caminho+=path[i];
        //ABRINDO ARQUIVO
        QString local = caminho + "/Pedidos.csv";
        std::ofstream a2;
        a2.open(local.toStdString());
        if(a2.is_open()){
            QString ajuste;
            for(int v=0;v<listaPed.getQuantidade();v++){
                ponteiro=listaPed[v];
                if(v+1==listaPed.getQuantidade()){
                    if(typeid (*ponteiro)==typeid (Pedido)){
                        ajuste+="P"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getNumeroPedido())+
                                "\nStatus: "+dynamic_cast<Pedido*>(ponteiro)->getStatus() +
                                "\nData: "+dynamic_cast<Pedido*>(ponteiro)->getData() +
                                "\nValor Total:R$"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getValorTotal())+
                                "\nItens - código: "+dynamic_cast<Pedido*>(ponteiro)->getCodItem()+
                                "\nQuantidade de cada Item: "+dynamic_cast<Pedido*>(ponteiro)->getQuantidade()+
                                "\nPreço Unitário de cada Item: "+dynamic_cast<Pedido*>(ponteiro)->getUnitario();
                    }
                }
                else{
                    if(typeid (*ponteiro)==typeid (Pedido)){
                        ajuste+="P"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getNumeroPedido())+
                                "\nStatus: "+dynamic_cast<Pedido*>(ponteiro)->getStatus() +
                                "\nData: "+dynamic_cast<Pedido*>(ponteiro)->getData() +
                                "\nValor Total:R$"+QString::number(dynamic_cast<Pedido*>(ponteiro)->getValorTotal())+
                                "\nItem - código: "+dynamic_cast<Pedido*>(ponteiro)->getCodItem()+
                                "\nQuantidade: "+dynamic_cast<Pedido*>(ponteiro)->getQuantidade()+
                                "\nPreço Unitário: "+dynamic_cast<Pedido*>(ponteiro)->getUnitario()+"\n";
                    }
                }
            }
            a2<<ajuste.toStdString().c_str();
            a2.close();
        }
    }
    else{//cria o arquivo
        QString caminho="";
        int tamanho = path.size()-28;//-28 = nome do arquivo executável
        for(int i=0;i<tamanho;i++)
                caminho+=path[i];
        //ABRINDO ARQUIVO
        QString local = caminho + "/Pedidos.csv";
        std::ifstream ll;
        ll.open(local.toStdString());
        if(!ll.is_open()){
            std::ofstream arquivoo;
            arquivoo.open(local.toStdString());
        }
        ll.close();
    }
}
