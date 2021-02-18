#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <produto.h>

class Notebook : public Produto
{
protected:
    string marca;
    string modelo;
    string memoriaRAM;
    string capacidadeHD;
    string processador;
    double tamanhoTela;
    string so;
public:
    Notebook(string marca, string modelo, string memoriaRAM, string capacidadeHD, string processador, double tamanhoTela,
             int cod, string descricao, double preco, string tipo);
    string getMarca(){return marca;}
    void setMarca(string marca){this->marca=marca;}
    string getModelo(){return modelo;}
    void setModelo(string modelo){this->modelo=modelo;}
    string getMemoria(){return memoriaRAM;}
    void setMemoria(string memoria){this->memoriaRAM=memoria;}
    string getHD(){return capacidadeHD;}
    void setHD(string hd){this->capacidadeHD=hd;}
    string getProcessador(){return processador;}
    void setProcessador(string processador){this->processador=processador;}
    double getTamanhoTela(){return tamanhoTela;}
    void setTamanhoTela(double tela){this->tamanhoTela=tela;}
    string getSO(){return so;}
    void setSO(string so){this->so=so;}
};

#endif // NOTEBOOK_H
