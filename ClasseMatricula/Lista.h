#ifndef LISTATEMPLATE_H
#define LISTATEMPLATE_H
#include<iostream>
#include<string>
#include <sstream>

using namespace std;
template<typename A>
class Objeto{
private:
    A conteudo;
    A *ponteiro;
    Objeto<A> *pProximo;
    Objeto<A> *pAnterior;
public:
    Objeto(){
        pProximo=nullptr;
        pAnterior=nullptr;
        conteudo = 0 ;
    }
    virtual ~Objeto(){
        if (pAnterior != nullptr)
        delete pAnterior;
    }
    A getConteudo()const {return conteudo;}
    void setConteudo(A numero) {conteudo = numero;}
    Objeto<A> *getProximo()const {return pProximo;}
    void setProximo(Objeto<A> *Proximo) {pProximo = Proximo;}
    Objeto<A> *getAnterior()const {return pAnterior;}
    void setAnterior(Objeto<A> *Anterior) {pAnterior = Anterior;}
    string paraString(){
        stringstream saida;
        saida << this->getConteudo();
        return saida.str();
    }
    A *getObj(){return ponteiro;}
    bool operator <= (Objeto<A> & elemento) {return *(this->getObj()) <= *(elemento->getObj());}
    bool operator < (Objeto<A> & elemento) {return *(this->getObj()) < *(elemento->getObj());}
    bool operator >= (Objeto<A> & elemento) {return *(this->getObj()) >= *(elemento->getObj());}
    bool operator > (Objeto<A> & elemento) {return *(this->getObj()) > *(elemento->getObj());}
    bool operator == (Objeto<A> & elemento) {return *(this->getObj()) == *(elemento->getObj());}
};
template<typename A>
class Lista {
private:
    Objeto<A> *pInicio;
    Objeto<A> *pFim;
    int quantidade;
public:
    Lista(){
       pInicio= nullptr;
       pFim= nullptr;
        quantidade=0;
    }
    virtual ~Lista(){
      if (!estaVazia())
      {delete pInicio;}
    }
    int getQuantidade() const {
        return quantidade;
    }
    bool consultar(A data)
    {
        if(estaVazia()) return false;
        Objeto<A>* aux =pInicio;
        while(aux!=nullptr and aux->getConteudo()!=data) aux = aux->getProximo();
        if(aux==nullptr) return false;
        else
            return true;
    }
    bool estaVazia(){return quantidade==0;}
    void inserir(Objeto<A> *novo){
        try
        {
            if(estaVazia()){
               pInicio=pFim=novo;
               quantidade++;
           }else{
               Objeto<A> *aux=pFim;
               for(int i=0; i<quantidade; i++){
                   if(aux->getConteudo()>novo->getConteudo()){
                       aux=aux->getAnterior();
                           if(aux==nullptr){
                               pInicio->setAnterior(novo);
                               novo->setProximo(pInicio);
                               pInicio=novo;
                               quantidade++;
                               break;
                           }
                   }else if((aux->getConteudo() <= novo->getConteudo()) && (aux->getProximo()==nullptr)){
                       aux->setProximo(novo);
                       novo->setAnterior(aux);
                       pFim=novo;
                       quantidade++;
                       break;
                   }else if((aux->getConteudo() <= novo->getConteudo()) && (aux->getProximo()!=nullptr)){
                       novo->setAnterior(aux);
                       novo->setProximo(aux->getProximo());
                       aux->setProximo(novo);
                       aux=novo->getProximo();
                       aux->setAnterior(novo);
                       quantidade++;
                       break;
                   }else if(aux==nullptr){
                       pInicio->setAnterior(novo);
                       novo->setProximo(pInicio);
                       pInicio=novo;
                       quantidade++;
                       break;
                   }
               }
           }
        }
        catch(std::bad_alloc)
        {
            throw string("Memoria insuficiente, nao foi possivel criar um ELemento.");
        }
       }
    A retirar(A elemento)
    {
        if(estaVazia()) throw string("Lista Vazia");
        Objeto<A>* aux =pInicio;
        while(aux!=nullptr && aux->getConteudo()!=elemento) aux=aux->getProximo();
        if(aux==nullptr) throw string("VALOR NAO ENCONTRADO");
        if(quantidade==1){
            aux=pInicio;
            pInicio=pFim=0;
            quantidade=0;
            elemento=aux->getConteudo();
            delete aux;
            return elemento;
        }
        else{
            aux=pInicio;
            pInicio=aux->getProximo();
            pInicio->setAnterior(0);
            elemento = aux->getConteudo();
            delete aux;
            quantidade--;
            return elemento;
        }
    }
    void imprimir() {
        if(estaVazia()) throw string("Lista Vazia");
        cout << "Inicio: ";
        Objeto<A>* temp =pInicio;
        while(temp) {
            cout << temp->paraString() << " <-> ";
            temp = temp->getProximo();
        }
        cout << "\b\b\b\b :Fim" << endl;
    }
};

#endif // LISTATEMPLATE_H
