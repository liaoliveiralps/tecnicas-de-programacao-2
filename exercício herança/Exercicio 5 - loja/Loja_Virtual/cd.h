#ifndef CD_H
#define CD_H
#include <produto.h>

class CD : public Produto
{
protected:
    string nomeAlbum;
    string banda;
    string cantor;
    string genero;
public:
    CD(string nomeAlbum, string banda, string cantor, string genero, int cod, string descricao, double preco, string tipo);
    string getAlbum(){return nomeAlbum;}
    void setAlbum(string nomeAlbum){this->nomeAlbum=nomeAlbum;}
    string getBanda(){return banda;}
    void setBanda(string banda){this->banda=banda;}
    string getCantor(){return cantor;}
    void setCantor(string cantor){this->cantor=cantor;}
    string getGenero(){return genero;}
    void setGenero(string genero){this->genero=genero;}
};

#endif // CD_H
