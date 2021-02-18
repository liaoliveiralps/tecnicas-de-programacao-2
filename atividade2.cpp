#include <iostream>
#include <string>
using namespace std;
int main()
{
	string cnpj, ultimoDigito, penultimoDigito;
	cout<<"Informe seu CNPJ: ";
	cin>>cnpj;
	while(cnpj.length()!=14){
		cout<<"CNPJ incompleto, digite novamente: ";
		cin>>cnpj;
	}
	std::string::iterator i;
	for(i=cnpj.begin(); i!=cnpj.end(); i++){
		while(*i<'0' or *i>'9'){
			cout<<"CNPJ invalido, digite novamente: ";
			cin>>cnpj;
		}
	}
	ultimoDigito = cnpj.back();
	penultimoDigito = cnpj.at(12);
	string aux1(cnpj, 0, 4);
	string aux2(cnpj, 4, 8);
	std::string::iterator it;
	int cont=5;
	int valor1=0;
	for (it=aux1.begin(); it!=aux1.end(); it++){
		int a = (*it-48)*cont;
 		cont--;
 		valor1 += a;
	}
	std::string::iterator it1;
	cont=9;
	for (it1=aux2.begin(); it1!=aux2.end(); it1++){
		int a = (*it1-48)*cont;
		cont--;
		valor1 += a;
	}
	int digitoUm;
	if(valor1%11<2)
		digitoUm = 0;
	else if(valor1%11>=2)
			digitoUm = 11-(valor1%11);
	aux2.append(to_string(digitoUm));
	
	
	string aux3(cnpj, 0, 5);
	string aux4(aux2, 1, 8);
	std::string::iterator it2;
	int cont2=6;
	int valor2=0;
	for (it2=aux3.begin(); it2!=aux3.end(); it2++){
		int a = (*it2-48)*cont2;
 		cont2--;
 		valor2 += a;
	}
	std::string::iterator it3;
	cont2=9;
	for (it3=aux4.begin(); it3!=aux4.end(); it3++){
		int a = (*it3-48)*cont2;
		cont2--;
		valor2 += a;
	};
	int digitoDois;
	if(valor2%11<2)
		digitoDois = 0;
	else if(valor2%11>=2)
			digitoDois = 11-(valor2%11);
	cout<<"Os ultimos digitos corretos sao: "<<digitoUm<<" e "<<digitoDois;
	if(to_string(digitoUm)!=penultimoDigito or to_string(digitoDois)!=ultimoDigito)
		cout<<"\nOs ultimos digitos sao diferentes. CNPJ invalido";
	else
		cout<<"\nOs ultimos digitos sao iguais. CNPJ valido";
}
