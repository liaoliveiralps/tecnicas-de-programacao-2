#include "pessoa.h"
using namespace std;
Pessoa::Pessoa():
    codigo(),
    logradouro(),
    setor(),
    cidade(),
    estado(),
    telefone(),
    email()
{}
Pessoa::Pessoa(string codigo,QString logradouro,QString setor,QString cidade,QString estado,QString telefone,QString email):
    codigo(codigo),
    logradouro(logradouro),
    setor(setor),
    cidade(cidade),
    estado(estado),
    telefone(telefone),
    email(email)
{

}
Pessoa_Fisica::Pessoa_Fisica():
    cpf(""),
    nome(""),
    celular("")
{}
Pessoa_Fisica::Pessoa_Fisica(string codigo,QString logradouro,QString setor,QString cidade,QString estado,QString telefone,QString email,string cpf,QString nome,QString celular):
    Pessoa(codigo,logradouro,setor,cidade,estado,telefone,email),
    cpf(cpf),
    nome(nome),
    celular(celular)
{}
PessoaJuridica::PessoaJuridica():
    CNPJ(""),
    razaoSocial(""),
    nomeContato("")
{}
PessoaJuridica::PessoaJuridica(string codigo,QString logradouro,QString setor,QString cidade,QString estado,QString telefone,QString email,string CNPJ,QString razaoSocial,QString nomeContato):
    Pessoa(codigo,logradouro,setor,cidade,estado,telefone,email),
    CNPJ(CNPJ),
    razaoSocial(razaoSocial),
    nomeContato(nomeContato)
{}
bool Pessoa::operator == (const Pessoa& pessoa) const{
    int hlp11=atoi(getCodigo().c_str()), hlp22=atoi(pessoa.getCodigo().c_str());
    if(hlp22 == hlp11){
        return true;
    }
    return false;
}
bool Pessoa::operator != (const Pessoa& pessoa) const{
    int hlp11=atoi(getCodigo().c_str()), hlp22=atoi(pessoa.getCodigo().c_str());
    if(hlp22 != hlp11){
        return true;
    }
    return false;
}
bool Pessoa::operator < (const Pessoa& pessoa) const{
    int hlp11=atoi(getCodigo().c_str()), hlp22=atoi(pessoa.getCodigo().c_str());
    if(hlp11 < hlp22){
        return true;
    }
    return false;
}
bool Pessoa::operator <= (const Pessoa& pessoa) const{
    int hlp11=atoi(getCodigo().c_str()), hlp22=atoi(pessoa.getCodigo().c_str());
    if(hlp11 <= hlp22){
        return true;
    }
    return false;
}
bool Pessoa::operator > (const Pessoa& pessoa) const{
    int hlp11=atoi(getCodigo().c_str()), hlp22=atoi(pessoa.getCodigo().c_str());
    if(hlp11 > hlp22){
        return true;
    }
    return false;
}
bool Pessoa::operator >= (const Pessoa& pessoa) const{
    int hlp11=atoi(getCodigo().c_str()), hlp22=atoi(pessoa.getCodigo().c_str());
    if(hlp11 >= hlp22){
        return true;
    }
    return false;
}
bool Pessoa_Fisica::validarCpf(string cpf){
    string ultimoDigito, penultimoDigito, aux2;
    if(cpf.length()!=11) throw QString("Tamanho Invalido");
    string x1(cpf,0,1), x2(cpf,1,1), x3(cpf,2,1), x4(cpf,3,1), x5(cpf,4,1)
            , x6(cpf,5,1), x7(cpf,6,1), x8(cpf,7,1), x9(cpf,8,1), x10(cpf,9,1), x11(cpf,10,1);
    if(x1==x2 and x2==x3 and x3==x4 and x4==x5 and x5==x6
            and x6==x7 and x7==x8 and x8==x9 and x9==x10 and x10==x11)
        throw QString("Digítos do CPF são iguais, portanto, CPF inválido");
    std::string::iterator i;
    for(i=cpf.begin(); i!=cpf.end(); i++)
        if(*i<'0' or *i>'9') throw QString("CPF inválido");
    ultimoDigito = cpf.back();
    penultimoDigito = cpf.at(9);
    string aux(cpf, 0, 9);
    std::string::reverse_iterator it1;
    int cont=2;
    int valor=0;
    for (it1=aux.rbegin(); it1!=aux.rend(); it1++){
        int a = (*it1-48)*cont;
        cont++;
        valor+=a;
    }
    int digitoUm=0;
    if(valor%11<2) digitoUm = 0;
    else if(valor%11>=2)
        digitoUm = 11-(valor%11);
    aux.append(to_string(digitoUm));
    int cont1 = 2;
    int valor1 = 0;
    for (it1=aux.rbegin(); it1!=aux.rend(); it1++){
        int a = (*it1-48)*cont1;
        cont1++;
        valor1+=a;
    }
    int digitoDois=0;
    if(valor1%11<2) digitoDois = 0;
    else if(valor1%11>=2)
        digitoDois = 11-(valor1%11);
    if(to_string(digitoUm)!=penultimoDigito or to_string(digitoDois)!=ultimoDigito)
        return false;
    else
        return true;
}
bool PessoaJuridica::validarCnpj(string cnpj){
    string::iterator it2;
    if(cnpj.length()!=14){
        throw QString("Tamanho Invalido\n");
    }
    for (it2=cnpj.begin(); it2!=cnpj.end(); it2++){
        if(*it2-0>64 && *it2-0<123){
            throw QString("Nao pode exister letra no Cnpj\n");
        }
    }
    string aux=cnpj;
    aux.resize(12);
    string::reverse_iterator it1;
    int v=2, soma=0, r=2, verificador1, verificador2;
    for(it1=aux.rbegin();it1!=aux.rend();it1++){
        if(v<10){
            soma+=(*it1-48)*v;
            v++;
        }
        else{
            soma+=(*it1-48)*r;
            r++;
        }
    }
    soma=soma%11;
    if(soma<2){
        verificador1=0;
    }
    else{
        verificador1=11-soma;
    }
    v=3;
    soma=0;
    r=2;
    for(it1=aux.rbegin();it1!=aux.rend();it1++){
        if(v<10){
            soma+=(*it1-48)*v;
            v++;
        }
        else{
            soma+=(*it1-48)*r;
            r++;
        }
    }
    soma+=verificador1*2;
    soma=soma%11;
    if(soma<2){
        verificador2=0;
    }
    else{
        verificador2=11-soma;
    }
    int ultimo=cnpj.back()-48, penultimo=cnpj.at(12)-48;
    string saida;
    if(penultimo==verificador1 && ultimo==verificador2){
        return true;
    }
    else{
        return false;
    }
}
