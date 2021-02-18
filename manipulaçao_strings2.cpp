#include<iostream>
#include<string> // classe string
using namespace std;
int main()
{
 // Inicializando a string
 string str = "Tecnicas de programacao"; //21 letras e dois espacos

 // Mostrando string
 cout << "A string inicial e : ";
 cout << str << endl;

 // Redimensionando a string usando resize()
 str.resize(13);

 // Mostrando string
 cout << "A string depois do redimensionamento e : ";
 cout << str << endl;

 // Mostrando a capacidade da string
 cout << "A capacidade da string e : ";
 cout << str.capacity() << endl;

 // Mostrando o comprimento da string
 cout<<"O comprimento da string e :"<<str.length()<<endl;

 // Decrementando a capacidade da string string usando shrink_to_fit()
 str.shrink_to_fit();

 // Mostrando string
 cout << "The new capacity after shrinking is : ";
 cout << str.capacity() << endl;

 return 0;

} 
