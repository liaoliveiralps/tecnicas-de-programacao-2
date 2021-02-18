#ifndef ALUNO_H
#define ALUNO_H
#include<iostream>
#include<string>

class Aluno{
private:
    int matricula;
    float n1, n2, media;
    std::string nome;
public:
    Aluno(){
        matricula=0;
        n1=0;
        n2=0;
        nome="";
    }
    std::string getNome() const;
    void setNome(std::string nome);
    int getMatricula() const{return matricula;}
    void setMatricula(int matricula){this->matricula = matricula;}
    float getN1() const{return n1;}
    void setN1(float n1){this->n1 = n1;}
    float getN2() const{return n2;}
    void setN2(float n2){this->n2 = n2;}
    float getMedia(){return media=((n1+n2)/2);}
};

#endif // ALUNO_H
