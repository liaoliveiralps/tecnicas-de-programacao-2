#include "pessoafisica.h"

PessoaFisica::PessoaFisica(string cpf1, string sexo1, double renda1, string nome1,
                           string endereco1, string telefone1, string email1):
    Pessoa(nome1, endereco1, telefone1, email1),
    cpf(cpf1),
    sexo(sexo1),
    renda(renda1)
{

}
double PessoaFisica::calculoIR(){
    if(renda>0 and renda<=1.400) return 0.0;
    else if(renda>1.400 and renda<=2.100) return renda*0.1;
    else if(renda>2.100 and renda<=2.800) return renda*0.15;
    else if(renda>2.800 and renda<=3.600) return renda*0.25;
    else
        return renda*0.3;
}
