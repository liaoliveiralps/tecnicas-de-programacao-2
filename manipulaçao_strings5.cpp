#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
 // Varios construtores da classe string
 // incializando por a string em linha
 string str1("primeira string");
 // inicializando por outra string
 string str2(str1);
 // inicializacao por caractere com numero de ocorrencias
 string str3(5, '#');
 // inicializacao com parte de outra string
 string str4(str1, 6, 6); // a partir do sexto (segundo parametro)
 // 6 caracteres (terceiro parametro)
 // inicializacao por parte de outra string : versao iterator
 string str5(str2.begin(), str2.begin() + 5);
 cout << str1 << endl;
 cout << str2 << endl;
 cout << str3 << endl;
 cout << str4 << endl;
 cout << str5 << endl;
 // associando via operador
 string str6 = str4;
 // funcao clear deleta todos caracteres a partir da string
 str4.clear();
 // ambos size() e length() retornam o comprimento da string e
 // eles trabalham como sinonimos
 int len = str6.length(); // Mesmo que "len = str6.size();"
 cout << "Comprimento da string e : " << len << endl;
 // um caractere particular pode ser acessado usando at /
 // o operador []
 char ch = str6.at(2); // Mesmo que "ch = str6[2];"
 cout << "Terceiro caractere da string e : " << ch << endl;
 // funcao front retorna o primneiro caractere
 // e a funcao back retorna o ultimo caractere da string
 char ch_f = str6.front(); // Mesmo que "ch_f = str6[0];"
 char ch_b = str6.back(); // Mesmo que "ch_b = str6[str6.length() -1];"
 cout << "Primeiro char e : " << ch_f << ", Ultimo char e : "
 << ch_b << endl;
 // c_str retorna uma versao da string como vetor terminado com nul
 const char* charstr = str6.c_str();
 printf("%s\n", charstr);
 // O metodo append adiciona o argumento no fim da string
 str6.append(" extensao");
 // mesmo que str6 += " extensao"
 // outra versao do append, acrescenta parte de outra string
 str4.append(str6, 0, 6); // na posicao 0 6 caracteres
 cout << str6 << endl;
 cout << str4 << endl;
 // find retorna indice onde o padrao e encontrado.
 // Se o padrao nao for encontrado, ele retornara a constante npos
 // predefinida com valor -1

 if (str6.find(str4) != string::npos)
 cout << "str4 foi encontrado em str6 no indice " <<
str6.find(str4)
 << " pos" << endl;
 else
 cout << "str4 nao foi encontrado em str6" << endl;
 // funcao substr(a, b) retorna uma substring de comprimento b
 // iniciando em a
 cout << str6.substr(7, 3) << endl;
 // se o segundo argumento nao for passado, uma substring até o fim
 // da string será retornada
 cout << str6.substr(7) << endl;
 // erase(a, b) deleta b caracteres a partir de a
 str6.erase(7, 4);
 cout << str6 << endl;
 // versao iterator do erase
 str6.erase(str6.begin() + 5, str6.end() - 3);
 cout << str6 << endl;
 str6 = "Este e um exemplo ";
 // replace(a, b, str) substitui b caracteres a partir de a por str
 str6.replace(2, 7, "apenas um teste");
 cout << str6 << endl;
 return 0;
}
