#include "pessoajuridica.h"

PessoaJuridica::PessoaJuridica(string cnpj1, string razaoSocial1, double rendaAnual1,
                               string nome1, string endereco1, string telefone1, string email1):
    Pessoa(nome1, endereco1, telefone1, email1),
    cnpj(cnpj1),
    razaoSocial(razaoSocial1),
    rendaAnual(rendaAnual1)
{

}
