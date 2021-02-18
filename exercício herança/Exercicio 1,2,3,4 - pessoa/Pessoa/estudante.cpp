#include "estudante.h"

Estudante::Estudante(string matricula, string curso, string campus, string nome1, string endereco1, string telefone1, string email1):
    Pessoa(nome1,endereco1,telefone1,email1),
    matricula(matricula),
    curso(curso),
    campus(campus)
{

}
