#include<iostream>
#include<string> // classe string
using namespace std;
int main()
{
 // Inicializando string`
 string str = "Tecnicas de Programacao";

 // Declarando iterator
 std::string::iterator it;

 // Declarando iterator reverso
 std::string::reverse_iterator it1;

 // Mostrando a string
 cout << "A string usando iterador com avanço e : ";
 for (it=str.begin(); it!=str.end(); it++)
 cout << *it;
 cout << endl;

 // Mostrando a string reversa
 cout << "A string reversa usando o iterador reverso e : ";
 for (it1=str.rbegin(); it1!=str.rend(); it1++)
 cout << *it1;
 cout << endl;

 return 0;

} 
