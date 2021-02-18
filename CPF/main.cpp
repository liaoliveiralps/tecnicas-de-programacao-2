#include <string>
#include <iostream>
using namespace std;
#include <QString>

int main()
{
    string cpf, ultimoDigito, penultimoDigito, aux2;
    cout<<"Informe seu cpf: ";
    cin>>cpf;
    string x1(cpf,0,1), x2(cpf,1,1), x3(cpf,2,1), x4(cpf,3,1), x5(cpf,4,1)
            , x6(cpf,5,1), x7(cpf,6,1), x8(cpf,7,1), x9(cpf,8,1), x10(cpf,9,1), x11(cpf,10,1);
    if(x1==x2 and x2==x3 and x3==x4 and x4==x5 and x5==x6
            and x6==x7 and x7==x8 and x8==x9 and x9==x10 and x10==x11){
        cout<<"Digitos do CPF sao iguais.";
        return 0;
    }
    if(cpf.length()!=11) throw QString("CPF não possui 11 digítos");
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
    cout<<"Os ultimos digitos corretos sao: "<<digitoUm<<" e "<<digitoDois;
    if(to_string(digitoUm)!=penultimoDigito or to_string(digitoDois)!=ultimoDigito)
        cout<<"\nOs ultimos digitos sao diferentes. CPF invalido";
    else
        cout<<"\nOs ultimos digitos sao iguais. CPF valido";
}
