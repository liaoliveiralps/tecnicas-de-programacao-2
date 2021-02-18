#ifndef LIVRO_H
#define LIVRO_H
#include <produto.h>

class Livro : public Produto
{
protected:
    string autor;
    string tradutor;
    string editora;
    int ano;
public:
    Livro(string autor, string tradutor, string editora, int ano, int cod, string descricao, double preco, string tipo);
    string getAutor(){return autor;}
    void setAutor(string autor){this->autor=autor;}
    string getTradutor(){return tradutor;}
    void setTradutor(string trad){tradutor=trad;}
    string getEditora(){return editora;}
    void setEditora(string editora){this->editora=editora;}
    int getAno(){return ano;}
    void setAno(int ano){this->ano=ano;}
};

#endif // LIVRO_H
