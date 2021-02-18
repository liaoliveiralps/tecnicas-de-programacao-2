#ifndef PESSOA_H
#define PESSOA_H
#include<QString>
#include"llde.h"
using std::string;
class Pessoa
{
private:
    string codigo;
    QString logradouro;
    QString setor;
    QString cidade;
    QString estado;
    QString telefone;
    QString email;
public:
    Pessoa();
    Pessoa(string codigo,QString logradouro,QString setor,QString cidade,QString estado,QString telefone,QString email);
    virtual ~Pessoa(){}
    string getCodigo() const{return codigo;}
    void setCodigo(const string codigo){this->codigo=codigo;}
    QString getLogradouro() const{return logradouro;}
    void setLogradouro(const QString logradouro){this->logradouro=logradouro;}
    QString getSetor() const{return setor;}
    void setSetor(const QString setor){this->setor=setor;}
    QString getCidade() const{return cidade;}
    void setCidade(const QString cidade){this->cidade=cidade;}
    QString getEstado() const{return estado;}
    void setEstado(const QString estado){this->estado=estado;}
    QString getTelefone() const{return telefone;}
    void setTelefone(const QString telefone){this->telefone=telefone;}
    QString getEmail() const{return email;}
    void setEmail(const QString email){this->email=email;}
    bool operator == (const Pessoa& pessoa)const;
    bool operator != (const Pessoa& pessoa)const;
    bool operator < (const Pessoa& pessoa)const;
    bool operator <= (const Pessoa& pessoa)const;
    bool operator > (const Pessoa& pessoa)const;
    bool operator >= (const Pessoa& pessoa)const;
};
class Pessoa_Fisica:public Pessoa
{
private:
    string cpf;
    QString nome;
    QString celular;
public:
    Pessoa_Fisica();
    Pessoa_Fisica(string codigo,QString logradouro,QString setor,QString cidade,QString estado,QString telefone,QString email,string cpf,QString nome,QString celular);
    string getCpf() const{return cpf;}
    void setCpf(const string cpf){this->cpf=cpf;}
    QString getNome() const{return nome;}
    void setNome(const QString nome){this->nome=nome;}
    QString getCelular() const{return celular;}
    void setCelular(const QString celular){this->celular=celular;}
    static bool validarCpf(string cpf);
};
class PessoaJuridica : public Pessoa
{
private:
    string CNPJ;
    QString razaoSocial;
    QString nomeContato;
public:
    PessoaJuridica();
    PessoaJuridica(string codigo,QString logradouro,QString setor,QString cidade,QString estado,QString telefone,QString email,string CNPJ,QString razaoSocial,QString nomeContato);
    void setCNPJ(string cnpj){this->CNPJ = cnpj;}
    string getCNPJ()const {return CNPJ;}
    void setRazaoSocial(QString razaoSocial){this->razaoSocial = razaoSocial;}
    QString getRazaoSocial()const{return razaoSocial;}
    void setNomeContato(QString nomeContato){this->nomeContato = nomeContato;}
    QString getNomeContato()const {return nomeContato;}
    static bool validarCnpj(string cnpj);
};
#endif // PESSOA_H
