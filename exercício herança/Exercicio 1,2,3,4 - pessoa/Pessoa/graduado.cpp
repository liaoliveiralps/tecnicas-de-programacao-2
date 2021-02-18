#include "graduado.h"

Graduado::Graduado(int conclusao, int colacao, string diploma, string matricula1, string curso1,
                   string campus1, string nome1, string endereco1, string telefone1, string email1):
    Estudante(matricula1, curso1, campus1, nome1, endereco1, telefone1, email1),
    anoDaConclusao(conclusao),
    anoDaColacao(colacao),
    numeroDiploma(diploma)
{

}
