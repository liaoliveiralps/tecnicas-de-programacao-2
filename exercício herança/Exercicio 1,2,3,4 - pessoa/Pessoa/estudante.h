#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <pessoa.h>
#include <string>

class Estudante : public Pessoa
{
protected:
    string matricula;
    string curso;
    string campus;
public:
    Estudante(string matricula, string curso, string campus, string nome, string endereco, string telefone, string email);
    string getMatricula(){return matricula;}
    void setMatricula(string matricula){this->matricula=matricula;}
    string getCurso(){return curso;}
    void setCurso(string curso){this->curso=curso;}
    string getCampus(){return campus;}
    void setCampus(string campus){this->campus=campus;}
};

#endif // ESTUDANTE_H
