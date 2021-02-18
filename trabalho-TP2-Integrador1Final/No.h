#ifndef NO_H
#define NO_H
template <class T>
class No
{
private:
    T dado;
    No *anterior;
    No *proximo;
public:
    No();
    No(T dado);

    void setDado(T dado){this->dado = dado;}
    T getDado()const{return dado;}
    void setAnterior(No *no){anterior = no;}
    No* getAnterior()const{return anterior;}
    void setProximo(No *no){proximo = no;}
    No* getProximo()const{return proximo;}
};

template <class T>
No<T>::No():
    dado(0),
    anterior(0),
    proximo(0)
{
}

template <class T>
No<T>::No(T dado):
    dado(dado),
    anterior(0),
    proximo(0)
{
}
#endif // NO_H

