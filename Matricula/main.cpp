#include<iostream>
#include<fstream>
#include<string>
using std::string;
string saida(string login, string nome, string senha){
    string saida = "useradd -p `openssl passwd -crypt "+senha+"`-c'"+nome+"'"+login+"\n";
    return saida;
}
int main()
{
    try{

        string nome_arquivo = "logins.sh";
        //leitura do arquivo
        string arquivo("C:\\Users\\liand\\Downloads\\CMP-2.txt");
        string nome, login("a"), senha, leitura;
        string::iterator it1, it2;
        std::ifstream arquivof(arquivo.c_str());
        if(arquivof.fail()){
            throw string("Arquivo nÃ£o pode ser aberto.");
        }
        std::ofstream arquivoo(nome_arquivo.c_str());
        arquivoo<<"#!/bin/bash\n"<<std::endl;
        while (!arquivof.fail()) {
            int cont=1;
            int cont2;
            std::getline(arquivof, leitura);
            it1=leitura.begin();
            if(it1[10]=='.' and it1[8]=='.' and leitura.length()>10){
                for (it2 = leitura.begin(); it2 != leitura.end(); it2++) {
                    if(cont<20 and *it2!='.' and cont>4) login+=*it2;
                    cont++;
                }
                int aux=0, tam=0;
                for(cont2=0, it2=leitura.begin(); it2!=leitura.end(); it2++, cont2++){
                    if(aux==0 and cont2>24 and *it2==' ' and *(it2+1)==' '){
                        tam=cont2;
                        aux=1;
                    }
                }
                for(cont2=0, it2=leitura.begin(); it2!=leitura.end() and cont2!=1000; it2++, cont2++){
                    if(cont2>25 and cont2!=tam) nome+=*it2;
                    else
                        if(cont2==tam and cont2>25) cont2=999;
                }
                string numero;
                for(cont2=0, it2=leitura.begin(); cont2!=19 and it2!=leitura.end(); it2++, cont2++){
                    if(cont2>14) numero+=*it2;
                }
                string primeiroNome;
                int x1=0, x2=0;
                for(cont2=0, it2=leitura.begin(); it2!=leitura.end() and cont2!=999;it2++, cont2++){
                    if(cont2>25 and *it2==' ' and ((*(it2+1)=='D' and *(it2+2)=='E' and *(it2+3)==' ') or ( *(it2+3)==' ' and *(it2+1)=='D' and *(it2+2)=='A'))){
                        it2 += 4;
                        x1=1;
                    }
                    else{
                        if(cont2>25 and *it2==' ' and ((*(it2+1)=='D' and *(it2+2)=='A' and *(it2+3)=='S' and *(it2+4)==' ') or (*(it2+1)=='D' and *(it2+2)=='O' and *(it2+3)=='S' and *(it2+4)==' '))){
                            it2 += 5;
                            x1=1;
                        }
                        }
                        if(*it2!=' ' and x1==1 and cont2>26){
                            primeiroNome+=*it2;
                            if(*(it2+1)==' ') cont2=998;
                        }
                        else{
                            if(*it2==' ' and cont2>26){
                                x2=1;
                                it2++;
                            }
                            if(*it2!=' ' and x2==1){
                                primeiroNome+=*it2;
                                if(*(it2+1)==' ') cont2=998;
                            }
                        }
                    }
                string senha=numero+primeiroNome;
                //gravaÃ§Ã£o do arquivo
                arquivoo<<saida(login,nome,senha)<<std::endl;
            }
            login.clear();
            login="a";
            nome.clear();
            senha.clear();
        }
        arquivof.close();
        arquivoo.close();
        std::ifstream arquivoi(nome_arquivo.c_str());
        string linha;
        getline(arquivoi, linha);
        while(!arquivoi.fail()){
            std::cout<<linha<<std::endl;
            std::getline(arquivoi, linha);
        }
        }
        catch(string erro){
            std::cout<<erro;
        }
    }
