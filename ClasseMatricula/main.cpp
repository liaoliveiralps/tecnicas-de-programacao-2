
#include<iostream>
#include<string>
#include<fstream>
#include"Aluno.h"
#include"Lista.h"
using namespace std;
int entrada(){
   cout<<"1- Incluir um aluno"<<endl;
   cout<<"2- Excluir aluno"<<endl;
   cout<<"3- Consultar aluno"<<endl;
   cout<<"4- Listar alunos"<<endl;
   cout<<"0- Sair do programa"<<endl;
   int op;
   cin>>op;
   return op;
}
int main()
{
   fstream arquivo;
   string linha("");
   int numero;
   string nome;
   arquivo.open("alunos.csv", fstream::out); // abre o arquivo para escrita
    if (! arquivo){
        cout << "Arquivo saida.txt nao pode ser aberto" << endl;
        abort();
    }
    cout << "Entre com o numero e nome do funcionário\n";
    cout << "Fim de arquivo\n";
    while(cin >> numero >> nome)
    { arquivo << numero << " " << nome << '\n';
    cout << "?";
    }
    arquivo.close();
    return 0;
   }
