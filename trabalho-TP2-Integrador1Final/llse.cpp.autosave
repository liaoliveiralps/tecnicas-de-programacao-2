#include "llse.h"
namespace lia{
LLSE::LLSE():
    pInicio(0),
    pFim(0),
    quantidade(0)

{

}
LLSE::~LLSE()
{
    while (quantidade!=0) {
        retirarInicio();
    }
}

void LLSE::inserirInicio(int elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazio())
            pFim=pAux;
        pAux->setElo(pInicio); //conexão entre os elos
        pInicio=pAux;
        quantidade++;

    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }

}
int LLSE::retirarInicio(){
        No *pAux;
        if(estaVazio())
            throw QString("Impossivel tirar elemento, lista vazia\n");
        pAux=pInicio;
        pInicio=pAux->getElo();
        int aux = pAux->getInformacao();
        quantidade--;
        delete pAux;
        if(estaVazio())
            pFim=0;
        return aux;
}
void LLSE::inserirFim(int elemento){
    try {
        No* pAux = new No(elemento);
        if(estaVazio())
            pInicio=pAux;
        pAux->setElo(pFim); //conexão entre os elos
        pFim=pAux;
        quantidade++;

    } catch (std::bad_alloc&) {
        throw QString("Falta memoria\n");
    }
}
int LLSE::retirarFim(){
    if(estaVazio()) throw QString("Impossivel tirar elemento, lista vazia");
    if(quantidade==1){
        int valor = pFim->getInformacao();
        delete pFim;
        pFim = pInicio = 0;
        quantidade = 0;
        return valor;
    }
    No *pAux;
    pAux = pInicio;
    while(pAux->getElo()!=pFim)
        pAux = pAux->getElo();
    int valor = pFim->getInformacao();
    delete  pFim;
    pFim = pAux;
    pAux->setElo(0);
    quantidade--;
    return valor;
}
int LLSE::operator[](int posicao){
    if(posicao<0) throw QString("Posição não pode ser negativa");
    if(posicao>=quantidade) throw ("Posição inválida");
    if(estaVazio()) throw QString("Lista vazia");
    if(posicao==0)
        return pInicio->getInformacao();
    if(posicao==quantidade-1)
        return pFim->getInformacao();
    No *pAux;
    pAux = pInicio;
    int cont=0;
    while(cont<posicao){
        pAux = pAux->getElo();
        cont++;
    }
    return pAux->getInformacao();

}
}
