#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include <pessoa.h>
#include <string>

class Trabalhador: public Pessoa
{
protected:
    string funcao;
    string departamento;
    float salario;
public:
    Trabalhador(string funcao, string departamento, float salario, string nome, string endereco, string telefone, string email);
    string getFuncao(){return funcao;}
    void setFuncao(string funcao){this->funcao=funcao;}
    string getDepartamento(){return departamento;}
    void setDepartamento(string dep){departamento=dep;}
    float getSalario(){return salario;}
    void setSalario(float salario){this->salario=salario;}
};

#endif // TRABALHADOR_H
