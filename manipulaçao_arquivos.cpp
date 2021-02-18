//Contruir um programa crie um arquivo e escreva hellow world! e também abra o respecetivo arquivo,

//leia o texto contido e escreva na tela.

#include <iostream>

#include <fstream>//Biblioteca para trabalhar com arquivos

using namespace std;

int main() {

string nome;

cout<<"Digite o nome do arquivo a ser criado: ";

cin>>nome;



//gravacao no arquivo

ofstream arquivoo(nome.c_str()); //cria o arquivo com o nome

arquivoo << "!!!Hello World!!!" << endl; // grava no arquivo !!!Hello World!!!

arquivoo.close(); //fecha o arquivo.



//leitura do arquivo

string linha; //variavel que recebera a linha lida do arquivo

cout<<"Digite o nome do arquivo a ser lido: ";

cin>>nome;



ifstream arquivoi(nome.c_str());//abre o arquivo com o nome

if(arquivoi.fail()){ //testa se a abertura do arquivo falhou

cout<<"Arquivo "<<nome<<" nao aberto"<<endl;

}

else{//caso nao tenha falhado

getline(arquivoi, linha); //ler a primeira linha do arquivo

cout<<"Linha do arquivo "<<linha<<endl; //escrever na tela a linha lida do arquivo

arquivoi.close(); //fecha o arquivo

}

return 0;

}


