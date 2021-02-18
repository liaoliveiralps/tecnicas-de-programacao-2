#include <iostream>
#include <string>
using namespace std;
int main()
{
	// Declarando string
 string str;

 // Comando de entrada para uma string usando getline()
 getline(cin,str);
 
// Mostrando uma string
 cout << "O inicio da string e : ";
 cout << str << endl;
 
 // Usando push_back() para inserir um caractere no fim
 // inserindo 's' neste caso
 str.push_back('s');
 
 // Mostrando a string
 cout << "A string depois da operacao push_back e : ";
 cout << str << endl; 
 
 // Usando pop_back() para deletar um caractere do inicio
 // retirando 's' neste caso
 str.pop_back();

 // Mostrando a string
 cout << "A string depois da operacao after pop_back e : ";
 cout << str << endl; 

 return 0; 
}

