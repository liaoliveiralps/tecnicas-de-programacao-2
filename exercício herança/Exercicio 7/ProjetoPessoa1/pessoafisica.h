#ifndef PESSOFISICA_H
#define PESSOFISICA_H
#include <pessoa.h>

class PessoaFisica : public Pessoa
{
protected:
    string cpf;
    string sexo;
    double renda;
public:
    PessoaFisica(string cpf, string sexo, double renda, string nome, string endereco, string telefone, string email);

    string getCpf(){return cpf;}
    void setCpf(string cpf){this->cpf=cpf;}
    string getSexo(){return sexo;}
    void setSexo(string sexo){this->sexo=sexo;}
    double getRenda(){return renda;}
    void setRenda(double renda){this->renda=renda;}
    double calculoIR();
};

#endif // PESSOFISICA_H
