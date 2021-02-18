#include<iostream>
#include<string> // classe string
using namespace std;
int main()
{
 // Inicializando a primeira string 
 string str1 = "Tecnicas de Programacao";

 // Declarando a segunda string
 string str2 = "Estrutura de Dados";

 // Declarando o vetor de caracteres
 char ch[80];

 // usando copy() para copiar elementos dentro do vetor char
 // copia "Tecnicas"
 str1.copy(ch,8,0);

 // Mostrando o vetor char
 cout << "O novo vetor de caracteres copiado e : ";
 cout << ch << endl << endl;

 // Mostrando as strings antes da troca
 cout << "A primeira string antes da troca e : ";
 cout << str1 << endl;
 cout << "A segunda string antes da troca e : ";
 cout << str2 << endl;

 // usando swap() para trocar o conteudo da string
 str1.swap(str2);

 // Mostrando as string depois da troca
 cout << "A primeira string depois da troca e : ";
 cout << str1 << endl;
 cout << "A segunda string depois da troca e : ";
 cout << str2 << endl;

 return 0;

} 
