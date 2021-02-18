#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using namespace std;
class Pessoa
{
protected:
    string nome;
    string endereco;
    string telefone;
    string email;
public:
    Pessoa(string nome, string endereco, string telefone, string email);
    string getNome(){return nome;}
    void setNome(string nome1){nome=nome1;}
    string getEndereco(){return endereco;}
    void setEndereco(string endereco1){endereco=endereco1;}
    string getTelefone(){return telefone;}
    void setTelefone(string telefone1){telefone=telefone1;}
    string getEmail(){return email;}
    void setEmail(string email){this->email=email;}
};

#endif // PESSOA_H
