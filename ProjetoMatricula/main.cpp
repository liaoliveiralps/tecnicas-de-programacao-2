#include<iostream>
#include<fstream>
#include<string>
using std::string;
string saida(string login, string nome, string senha){
    string saida="useradd -p `openssl passwd -crypt "+senha+"`-c'"+nome+"'"+login+"\n";
    return saida;
}
int main()
{
    try{
    std::cout<<"#!/bin/bash\n";
    string arquivo("C:\\Users\\liand\\Downloads\\CMP-2.txt");
    string nome, login("a"), senha, leitura;
    string::iterator hp1, hp2;
    //Abre o arquivo
    std::ifstream arquivof(arquivo.c_str());
    //testa se a abertura do arquivo falhou
    if(arquivof.fail()){
        throw string("Arquivo nao aberto");
    }
    while (!arquivof.fail()) {
        int v=1, r;
        std::getline(arquivof, leitura);
        hp1=leitura.begin();
        if(leitura.length()>10 && hp1[7]=='.' && hp1[9]=='.'){
            //Login
            for (hp2=leitura.begin();hp2!=leitura.end();hp2++) {
                if(v<19 && *hp2!='.' && v>3){
                    login+=*hp2;
                }
                v++;
            }
            //Nome
            int var=0, tamanho=0;
            for(r=0 , hp2=leitura.begin(); hp2!=leitura.end(); hp2++, r++){
                if(*hp2==' ' && *(hp2+1)==' ' && var==0 && r>24){
                    tamanho=r;
                    var=1;
                }
            }
            for(r=0 , hp2=leitura.begin();r!=1000 && hp2!=leitura.end(); hp2++, r++){
                if(r>24 && r!=tamanho){
                    nome+=*hp2;
                }
                else{
                    if(r==tamanho && r>24){
                        r=999;
                    }
                }
            }
            //Senha
            string numero;
            //Pega 4 ult numeros
            for(r=0, hp2=leitura.begin();r!=18 && hp2!=leitura.end(); hp2++, r++){
                if(r>13){
                    numero+=*hp2;
                }
            }
            //Pega segundo nome
            int chave=0, chave2=0;
                string Partnome;
                for(r= 0, hp2=leitura.begin();r!=999 && hp2!=leitura.end();hp2++, r++){
                    if(r>25 && *hp2==' ' && ((*(hp2+1)=='D' && *(hp2+2)=='E' && *(hp2+3)==' ')||(*(hp2+1)=='D' && *(hp2+2)=='A' &&*(hp2+3)==' '))){
                        hp2++;
                        hp2++;
                        hp2++;
                        hp2++;
                        chave=1;
                    }
                    else{
                        if(r>25 && *hp2==' ' && ((*(hp2+1)=='D' && *(hp2+2)=='A' &&*(hp2+3)=='S' && *(hp2+4)==' ')||(*(hp2+1)=='D' && *(hp2+2)=='O' &&*(hp2+3)=='S' && *(hp2+4)==' '))){
                            hp2++;
                            hp2++;
                            hp2++;
                            hp2++;
                            hp2++;
                            chave=1;
                        }
                    }
                    if(r>25 && *hp2!=' ' && chave==1){
                        Partnome+=*hp2;
                        if(*(hp2+1)==' '){
                            r=998;
                        }
                    }
                    else{
                        if(r>25 && *hp2==' '){
                            chave2=1;
                            hp2++;
                        }
                        if(chave2==1 && *hp2!=' '){
                            Partnome+=*hp2;
                            if(*(hp2+1)==' '){
                                r=998;
                            }
                        }
                    }
                }
                string senha=numero+Partnome;
            std::cout<<saida(login,nome,senha);
        }
        login.clear();
        login="a";
        nome.clear();
        senha.clear();
    }
    }
    catch(string erro){
        std::cout<<erro;
    }
}
