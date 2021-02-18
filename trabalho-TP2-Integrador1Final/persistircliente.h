#ifndef PERSISTIRCLIENTE_H
#define PERSISTIRCLIENTE_H
#include"pessoa.h"
#include<string>
#include<QString>
#include<typeinfo>
class PersistirCliente
{
private:
    QString path;
    LLDE<Pessoa*> lista;
    Pessoa *hlp;
public:
    void persistir(int i);
    PersistirCliente();
    ~PersistirCliente(){hlp=new Pessoa; delete hlp;}
    void setLista();
    void validarPessoa(string cpfpj,int codigo);
    void cadastrar(int codigo,QString logradouro,string cpfpj,QString setor,QString cidade,QString estado,QString telefone,QString email,QString nr,QString cn);
    QString consultar(int codigo);
    void removerCliente(int codigo);
    QString listarClientes();
    LLDE<Pessoa*> getLista() const{return lista;}
    bool analisaPessoa(int codigo);
    void setPath(const QString path){this->path=path;}
};
#endif // PERSISTIRCLIENTE_H
