#ifndef LLDE_H
#define LLDE_H
#include "No.h"
#include <QString>
template <class T>
class LLDE
{
private:
    No<T>* pInicio;
    No<T>* pFim;
    int quantidade;
public:
    LLDE();
    ~LLDE(){while(quantidade) retirarInicio();}

    int getQuantidade()const{return quantidade;}
    bool estaVazio()const{return (quantidade==0);}

    void inserirInicio(T elemento);
    T retirarInicio();

    void inserirNaPosicao(int posicao,T elemento);
    T retirarNaPosicao(int posicao);

    void inserriFim(T elemento);
    T retirarFim();

    T operator [] (int posicao)const;

    void inserirOrdenado(T elemento);
    int consultar(T elemento)const;//retorna posicao
};

template <class T>
LLDE<T>::LLDE():
    pInicio(0),
    pFim(0),
    quantidade(0)
{
}
template <class T>
void LLDE<T>::inserirInicio(T elemento){
    try {
        No<T>* pAux = new No<T>(elemento);
        if(estaVazio()) {
            pInicio = pFim = pAux;
            quantidade++;
        }
        else{
            pAux->setProximo(pInicio);
            pInicio->setAnterior(pAux);
            pInicio = pAux;
            quantidade++;
        }
    } catch (std::bad_alloc&) {
        throw QString("Não foi possível criar o nó!");
    }

}
template <class T>
T LLDE<T>::retirarInicio(){
    if(estaVazio())
        throw QString("Impossível retirar, lista está vazia!");
    T valor;
    if(quantidade==1){
        valor = pInicio->getDado();
        delete pInicio;
        pInicio = pFim = 0;
        quantidade = 0;
        return valor;
    }
    No<T>* pAux;
    pAux = pInicio;
    pInicio = pInicio->getProximo();
    pInicio->setAnterior(0);
    quantidade--;
    valor = pAux->getDado();
    delete pAux;
    return valor;
}
template <class T>
void LLDE<T>::inserriFim(T elemento){
    try {
        No<T>* pAux = new No<T>(elemento);
        if(estaVazio()){
            pInicio = pFim = pAux;
        }
        else{
            pAux->setAnterior(pFim);
            pFim->setProximo(pAux);
            pFim = pAux;
        }
        quantidade++;
    } catch (std::bad_alloc&) {
        throw QString("Não foi possível criar o nó!");
    }
}
template <class T>
T LLDE<T>::retirarFim(){
    if(estaVazio())
        throw QString("Impossível retirar, lista está vazia!");
    T valor;
    if(quantidade==1){
        valor = pInicio->getDado();
        delete pInicio;
        pInicio = pFim = 0;
        quantidade = 0;
    }
    else{
        No<T>* pAux = pFim;
        pFim = pFim->getAnterior();
        pFim->setProximo(0);
        valor = pAux->getDado();
        quantidade--;
        delete pAux;
    }
    return valor;
}
template <class T>
T LLDE<T>::operator[](int posicao)const{
    if(posicao<0 || posicao>=quantidade) throw QString("Posicao inválida");
    if(estaVazio()) throw QString("Lista está vazia, não há nada para ser consultado");
    if(posicao == 0) return pInicio->getDado();
    if(posicao == quantidade-1) return pFim->getDado();
    No<T>* pAux = pInicio;
    while(posicao--)
        pAux = pAux->getProximo();
    T elemento = pAux->getDado();
    return elemento;
}
template <class T>
void LLDE<T>::inserirNaPosicao(int posicao,T elemento){
    try {
        if(posicao<0 || posicao>quantidade) throw QString("Posicao invalida");
        if(posicao==0) return inserirInicio(elemento);
        if(posicao==quantidade) return inserriFim(elemento);
        No<T>* pNo = new No<T>(elemento);
        No<T>* pAux;
        pAux = pInicio;
        for(int i=0; i<posicao; i++)
            pAux = pAux->getProximo();
        pAux->getAnterior()->setProximo(pNo);
        pNo->setAnterior(pAux->getAnterior());
        pAux->setAnterior(pNo);
        pNo->setProximo(pAux);
        quantidade++;
    } catch (std::bad_alloc) {
        throw QString("Não foi possiível criar o nó");
    }

}
template <class T>
T LLDE<T>::retirarNaPosicao(int posicao){
    if(posicao<0 || posicao>=quantidade) throw QString("Posicao inválida");
    if(posicao==0) return retirarInicio();
    if(posicao==quantidade-1) return retirarFim();
    No<T>* pAux = pInicio;
    for(int i=0 ; i<posicao;i++)
        pAux = pAux->getProximo();
    T valor = pAux->getDado();
    pAux->getAnterior()->setProximo(pAux->getProximo());
    pAux->getProximo()->setAnterior(pAux->getAnterior());
    quantidade--;
    return valor;

}
template <class T>
void LLDE<T>::inserirOrdenado(T elemento){
    if(estaVazio()) return inserirInicio(elemento);
    if( *(pInicio->getDado()) > *elemento ) return inserirInicio(elemento);
    if(*elemento > *(pFim->getDado())) return inserriFim(elemento);
    No<T>* aux = pInicio;
    int i;
    for(i=0;i < quantidade && *elemento > *aux->getDado();i++){
        aux = aux->getProximo();
    }
    inserirNaPosicao(i,elemento);
}
template <class T>
int LLDE<T>::consultar(T elemento)const{
    if(estaVazio()==true)
        return -1;
    No<T>* pAux = pInicio;
    for(int i=0;i<quantidade;i++){
        if(*(pAux->getDado()) == *elemento)
            return i;
        pAux = pAux->getProximo();
    }
    return -1;
    //retorna -1 quando não existe, -1 é uma posição inválida
}
#endif // LLDE_H
