#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <pessoa.h>

class PessoaJuridica : public Pessoa
{
protected:
    string cnpj;
    string razaoSocial;
    double rendaAnual;
public:
    PessoaJuridica(string cnpj, string razaoSocial, double rendaAnual,
                   string nome, string endereco, string telefone, string email);

    string getCnpj(){return cnpj;}
    void setCnpj(string cnpj){this->cnpj=cnpj;}
    string getRazaoSocial(){return razaoSocial;}
    void setRazaoSocial(string razao){this->razaoSocial=razao;}
    double getRendaAnual(){return rendaAnual;}
    void setRendaAnual(double renda){this->rendaAnual=renda;}
    double calculoIR(){return rendaAnual*0.1;}
};

#endif // PESSOAJURIDICA_H
