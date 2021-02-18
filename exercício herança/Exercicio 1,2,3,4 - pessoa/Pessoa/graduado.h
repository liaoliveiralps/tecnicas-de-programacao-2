#ifndef GRADUADO_H
#define GRADUADO_H
#include <estudante.h>

class Graduado : public Estudante
{
protected:
    int anoDaConclusao;
    int anoDaColacao;
    string numeroDiploma;
public:
    Graduado(int conclusao, int colacao, string diploma, string matricula,
             string curso, string campus, string nome, string endereco, string telefone, string email);
    int getConclusao(){return anoDaConclusao;}
    void setConclusao(int conclusao){anoDaConclusao=conclusao;}
    int getColacao(){return anoDaColacao;}
    void setColacao(int colacao){anoDaConclusao=colacao;}
    string getDiploma(){return numeroDiploma;}
    void setDiploma(string numDiploma){numeroDiploma=numDiploma;}
};

#endif // GRADUADO_H
