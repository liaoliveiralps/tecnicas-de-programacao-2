#include <QCoreApplication>
#include <iostream>
#include <QString>
struct Pessoa{
    QString nome;
    float peso;
    float altura;
    float calculoIMC(){
        return peso/(altura*altura);
    }
    };
int main()
{
    Pessoa p;
    p.nome = "Joao";
    p.peso = 70.5;
    p.altura = 1.8;
    std::cout<<"IMC: "<<p.calculoIMC()<<std::endl;
}
