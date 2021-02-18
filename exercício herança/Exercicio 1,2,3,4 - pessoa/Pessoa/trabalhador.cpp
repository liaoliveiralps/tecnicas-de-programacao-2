#include "trabalhador.h"

Trabalhador::Trabalhador(string funcao, string departamento, float salario, string nome1, string endereco1, string telefone1, string email1):
    Pessoa(nome1, endereco1, telefone1, email1),
    funcao(funcao),
    departamento(departamento),
    salario(salario)
{

}
