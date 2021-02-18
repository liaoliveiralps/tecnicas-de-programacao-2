#include<iostream>
#include<string>
#include <sstream>

using namespace std;

//CLASSE ELEMENTO PARA LISTA DUPLA ENC com TEMPLATE>

template<typename T>
class Elemento{

private:
    T	conteudo;
    T *obj;
    Elemento<T> *proximo;
    Elemento<T> *anterior;
public:

    Elemento(){
        proximo=nullptr;
        anterior=nullptr;
        conteudo = 0 ;
    }


    virtual ~Elemento(){
        if (anterior != nullptr)
        delete anterior;
    }

    T getConteudo()const{
        return conteudo;
    }
    void setConteudo(T numero){
        conteudo = numero;
    }
    Elemento<T> *getProximo()const{
        return proximo;
    }
    void setProximo(Elemento<T> *Proximo){
         proximo = Proximo;
    }
    Elemento<T> *getAnterior()const{
        return anterior;
    }
    void setAnterior(Elemento<T> *Anterior){
         anterior = Anterior;
    }
    string paraString(){
        stringstream s;
            s << this->getConteudo();
            return s.str();

    }
    T *getObj(){return obj;}
    bool operator <= (Elemento<T> & elemento){
         return *(this->getObj()) <= *(elemento->getObj());
    }
    bool operator < (Elemento<T> & elemento){
         return *(this->getObj()) < *(elemento->getObj());
    }
    bool operator >= (Elemento<T> & elemento){
         return *(this->getObj()) >= *(elemento->getObj());
    }
    bool operator > (Elemento<T> & elemento){
         return *(this->getObj()) > *(elemento->getObj());
    }
    bool operator == (Elemento<T> & elemento){
         return *(this->getObj()) == *(elemento->getObj());
    }


};

template<typename T>
class Lista {
private:
    Elemento<T> *inicio;
    Elemento<T> *fim;
    int qtde;

public:

    Lista(){
       inicio= nullptr;
       fim= nullptr;
        qtde=0;
    }

    virtual ~Lista(){
      if (!Vazia())
      {delete inicio;}
    }

    int getQtde() const {
        return qtde;
    }

    bool Vazia(){return qtde==0;}

    void inserir(Elemento<T> *novo){
        try
        {
           if(Vazia()){
               inicio=fim=novo;
               qtde++;
           }else{
               Elemento<T> *aux=fim;
               for(int i=0; i < qtde; i++){
                   if(aux->getConteudo() > novo->getConteudo()){
                       aux=aux->getAnterior();
                           if(aux==nullptr){
                               inicio->setAnterior(novo);
                               novo->setProximo(inicio);
                               inicio=novo;
                               qtde++;
                               break;
                           }
                   }else if((aux->getConteudo() <= novo->getConteudo()) && (aux->getProximo()==nullptr)){
                       aux->setProximo(novo);
                       novo->setAnterior(aux);
                       fim=novo;
                       qtde++;
                       break;
                   }else if((aux->getConteudo() <= novo->getConteudo()) && (aux->getProximo()!=nullptr)){
                       novo->setAnterior(aux);
                       novo->setProximo(aux->getProximo());
                       aux->setProximo(novo);
                       aux=novo->getProximo();
                       aux->setAnterior(novo);
                       qtde++;
                       break;
                   }else if(aux==nullptr){

                       inicio->setAnterior(novo);
                       novo->setProximo(inicio);
                       inicio=novo;
                       qtde++;
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



    T removerValor(T data)
    {
        if(Vazia())
        {
            throw string("Lista Vazia");
        }
        Elemento<T>* Aux =inicio;
        while(Aux!=nullptr && Aux->getConteudo()!=data)
        {
            Aux = Aux->getProximo();
        }
        if(Aux==nullptr)
        {
            throw string("VALOR NAO ENCONTRADO");
        }
        if(qtde==1)
              {
                Aux=inicio;
                inicio=fim=0;
                qtde=0;
                data=Aux->getConteudo();
                delete Aux;
                return data;
              }
        else
        {
            Aux=inicio;
            inicio=Aux->getProximo();
            inicio->setAnterior(0);
            data = Aux->getConteudo();
            delete Aux;
            qtde--;
            return data;
        }
    }




    bool Buscar(T data)
    {
        if(Vazia())
        {
            return false;
        }
        Elemento<T>* aux =inicio;
        while(aux!=nullptr && aux->getConteudo()!=data)
        {
            aux = aux->getProximo();
        }
        if(aux==nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void imprimir() {
        if(Vazia())
             {
               throw string("Lista Vazia");
             }
        cout << "Inicio: ";
        Elemento<T>* temp =inicio;
        while(temp) {
            cout << temp->paraString() << " <-> ";
            temp = temp->getProximo();
        }
        cout << "\b\b\b\b :Fim" << endl;
    }


};
