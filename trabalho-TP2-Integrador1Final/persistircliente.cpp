#include "persistircliente.h"
#include<fstream>
#include<string>
PersistirCliente::PersistirCliente():
    path(""),
    lista()
{}
void PersistirCliente::setLista()
{
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Clientes.csv";
    std::ifstream arquivoc;
    string linha1;
    arquivoc.open(local.toStdString());
    if(!arquivoc.is_open()){
        throw QString("Arquivo nao aberto");
    }
    string linha;
    //Pega usuarios no arquivo e joga na lista ordenada
    int chave=0, chave2=0;
    QString codigo1, nr1, cn1, cpfpj1,telefone1, email1, logradouro1, estado1, cidade1, setor1;
    while (!arquivoc.eof()) {
        getline(arquivoc,linha);
        string::iterator tp2;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                codigo1+=*tp2;
            }
            if(*tp2=='C'){
                chave=1;
            }
        }
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                nr1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                cn1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                cpfpj1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                telefone1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                email1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                logradouro1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                estado1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                cidade1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        getline(arquivoc,linha);
        tp2=linha.begin();
        for(;tp2!=linha.end();tp2++){
            if(chave2==1){
                setor1+=*tp2;
            }
            if(*tp2==':'){
                chave2=1;
            }
        }
        chave2=0;
        if(!codigo1.isEmpty()){
            if(cpfpj1.length()==11){
                hlp=new Pessoa_Fisica(codigo1.toStdString(),logradouro1,setor1,cidade1,estado1,telefone1,email1,cpfpj1.toStdString(),nr1,cn1);
            }
            else{
                hlp=new PessoaJuridica(codigo1.toStdString(),logradouro1,setor1,cidade1,estado1,telefone1,email1,cpfpj1.toStdString(),nr1,cn1);
            }
            lista.inserirOrdenado(hlp);
        }
        linha.clear();
        codigo1.clear();
        nr1.clear();
        cn1.clear();
        cpfpj1.clear();
        telefone1.clear();
        email1.clear();
        logradouro1.clear();
        estado1.clear();
        cidade1.clear();
        setor1.clear();
        chave=0;
    }
    arquivoc.close();
}
void PersistirCliente::validarPessoa(string cpfpj, int codigo){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Clientes.csv";
    Pessoa_Fisica cpf;
    PessoaJuridica cnpj;
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='C'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            if(codigo==hlp11){
                throw QString("Codigo ja cadastrado");
            }
        }
        linha.clear();
    }
    //Validar Cpf ou cnpj
    arquivoco.close();
    if(cpfpj.length()==11){
        if(!cpf.validarCpf(cpfpj)){
            throw QString("Cpf Invalido");
        }
    }
    else{
        if(!cnpj.validarCnpj(cpfpj)){
            throw QString("Cnpj Invalido");
        }
    }
    //Verificar se cpf ou cnpj ja existe
    std::ifstream arquivoc;
    arquivoc.open(local.toStdString());
    while (!arquivoc.eof()) {
        getline(arquivoc,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                chave=1;
            }
        }
        if(cpfpj.length()==11 && cpfpj==hlp1.toStdString()){
            throw QString("Cpf já cadastrado");
        }
        else{
            if(cpfpj.length()!=11 && cpfpj==hlp1.toStdString()){
                throw QString("Cnpj já cadastrado");
            }
        }
        linha.clear();
    }
    arquivoc.close();
}
void PersistirCliente::cadastrar(int codigo,QString logradouro,string cpfpj,QString setor,QString cidade,QString estado,QString telefone,QString email,QString nr,QString cn){
    if(cpfpj.length()==11){
        hlp=new Pessoa_Fisica(std::to_string(codigo),logradouro,setor,cidade,estado,telefone,email,cpfpj,nr,cn);
    }
    else{
        hlp=new PessoaJuridica(std::to_string(codigo),logradouro,setor,cidade,estado,telefone,email,cpfpj,nr,cn);
    }
    validarPessoa(cpfpj,codigo);
    lista.inserirOrdenado(hlp);
}
bool PersistirCliente::analisaPessoa(int codigo){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Clientes.csv";
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    int ok=0;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='C'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            if(codigo==hlp11){
                ok=1;
            }
        }
        linha.clear();
    }
    if(ok==0){
        return false;//cliente não existe
    }
    else
        return true;
}
QString PersistirCliente::consultar(int codigo){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Clientes.csv";
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    int ok=0;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='C'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            if(codigo==hlp11){
                ok=1;
            }
        }
        linha.clear();
    }
    if(ok==0){
        throw QString("Cliente não existe");
    }
    QString saida;
    int b=0;
    for(int v=0;v<lista.getQuantidade();v++){
        if(lista[v]->getCodigo()==std::to_string(codigo)){
            b=v;
            v=lista.getQuantidade();
        }
    }
    hlp=lista[b];
    if(typeid (*hlp)==typeid (Pessoa_Fisica)){
        saida=QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCodigo())+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getNome()+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getCelular()+"|"+QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCpf())+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getTelefone()+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getEmail()+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getLogradouro()+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getEstado()+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getCidade()+"|"+dynamic_cast<Pessoa_Fisica*>(hlp)->getSetor()+"-";
    }
    else{
        saida=QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCodigo())+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getRazaoSocial()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getNomeContato()+"|"+QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCNPJ())+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getTelefone()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getEmail()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getLogradouro()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getEstado()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getCidade()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getSetor()+"-";
    }
    arquivoco.close();
    return saida;
}
void PersistirCliente::removerCliente(int codigo){
    QString caminho="";
    int tamanho = path.size()-28;//-28 = nome do arquivo executável
    for(int i=0;i<tamanho;i++)
            caminho+=path[i];
    //ABRINDO ARQUIVO
    QString local = caminho + "/Clientes.csv";
    std::ifstream arquivoco;
    arquivoco.open(local.toStdString());
    if(!arquivoco.is_open()){
        throw QString("Arquivo nao Aberto");
    }
    //Validar Codigo
    string linha;
    int ok=0;
    while (!arquivoco.eof()) {
        getline(arquivoco,linha);
        string::iterator tp2;
        QString hlp1;
        int chave=0, trava=0;
        for(tp2=linha.begin();tp2!=linha.end();tp2++){
            if(chave==1){
                hlp1+=*tp2;
            }
            if(*tp2==':'){
                trava=1;
                chave=0;
            }
            if(*tp2=='C'&&trava==0){
                chave=1;
            }
        }
        if(chave==1){
            int hlp11=atoi(hlp1.toStdString().c_str());
            if(codigo==hlp11){
                ok=1;
            }
        }
        linha.clear();
    }
    if(ok==0){
        throw QString("Cliente não existe");
    }
    int b=0;
    for(int v=0;v<lista.getQuantidade();v++){
        if(lista[v]->getCodigo()==std::to_string(codigo)){
            b=v;
            v=lista.getQuantidade();
        }
    }
    arquivoco.close();
    lista.retirarNaPosicao(b);
}
QString PersistirCliente::listarClientes(){
    QString saida;
    for(int v=0;v<lista.getQuantidade();v++){
        hlp=lista[v];
        if(typeid (*hlp)==typeid (Pessoa_Fisica)){
            saida+=QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCodigo())+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getNome()+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getCelular()+"|"+
                    QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCpf())+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getTelefone()+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getEmail()+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getLogradouro()+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getEstado()+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getCidade()+"|"+
                    dynamic_cast<Pessoa_Fisica*>(hlp)->getSetor()+"-";
        }
        else{
            saida+=QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCodigo())+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getRazaoSocial()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getNomeContato()+"|"+QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCNPJ())+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getTelefone()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getEmail()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getLogradouro()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getEstado()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getCidade()+"|"+dynamic_cast<PessoaJuridica*>(hlp)->getSetor()+"-";
        }
    }
    return saida;
}

void PersistirCliente::persistir(int i){
    if(i==1){
        QString caminho="";
        int tamanho = path.size()-28;//-28 = nome do arquivo executável
        for(int i=0;i<tamanho;i++)
                caminho+=path[i];
        //ABRINDO ARQUIVO
        QString local = caminho + "/Clientes.csv";
        std::ofstream a2;
        a2.open(local.toStdString());
        if(a2.is_open()){
            QString ajuste;
            for(int v=0;v<lista.getQuantidade();v++){
                hlp=lista[v];
                if(v+1==lista.getQuantidade()){
                    if(typeid (*hlp)==typeid (Pessoa_Fisica)){
                        ajuste+="C"+QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCodigo())+"\nNome:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getNome()+"\nCelular:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getCelular()+"\nCpf:"+QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCpf())+"\nTelefone:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getTelefone()+"\nEmail:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getEmail()+"\nLogradouro:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getLogradouro()+"\nEstado:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getEstado()+"\nCidade:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getCidade()+"\nSetor:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getSetor();
                    }
                    else{
                        ajuste+="C"+QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCodigo())+"\nRazão Social:"+dynamic_cast<PessoaJuridica*>(hlp)->getRazaoSocial()+"\nNome Contato:"+dynamic_cast<PessoaJuridica*>(hlp)->getNomeContato()+"\nCnpj:"+QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCNPJ())+"\nTelefone:"+dynamic_cast<PessoaJuridica*>(hlp)->getTelefone()+"\nEmail:"+dynamic_cast<PessoaJuridica*>(hlp)->getEmail()+"\nLogradouro:"+dynamic_cast<PessoaJuridica*>(hlp)->getLogradouro()+"\nEstado:"+dynamic_cast<PessoaJuridica*>(hlp)->getEstado()+"\nCidade:"+dynamic_cast<PessoaJuridica*>(hlp)->getCidade()+"\nSetor:"+dynamic_cast<PessoaJuridica*>(hlp)->getSetor();
                    }
                }
                else{
                    if(typeid (*hlp)==typeid (Pessoa_Fisica)){
                        ajuste+="C"+QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCodigo())+"\nNome:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getNome()+"\nCelular:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getCelular()+"\nCpf:"+QString::fromStdString(dynamic_cast<Pessoa_Fisica*>(hlp)->getCpf())+"\nTelefone:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getTelefone()+"\nEmail:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getEmail()+"\nLogradouro:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getLogradouro()+"\nEstado:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getEstado()+"\nCidade:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getCidade()+"\nSetor:"+dynamic_cast<Pessoa_Fisica*>(hlp)->getSetor()+"\n";
                    }
                    else{
                        ajuste+="C"+QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCodigo())+"\nRazão Social:"+dynamic_cast<PessoaJuridica*>(hlp)->getRazaoSocial()+"\nNome Contato:"+dynamic_cast<PessoaJuridica*>(hlp)->getNomeContato()+"\nCnpj:"+QString::fromStdString(dynamic_cast<PessoaJuridica*>(hlp)->getCNPJ())+"\nTelefone:"+dynamic_cast<PessoaJuridica*>(hlp)->getTelefone()+"\nEmail:"+dynamic_cast<PessoaJuridica*>(hlp)->getEmail()+"\nLogradouro:"+dynamic_cast<PessoaJuridica*>(hlp)->getLogradouro()+"\nEstado:"+dynamic_cast<PessoaJuridica*>(hlp)->getEstado()+"\nCidade:"+dynamic_cast<PessoaJuridica*>(hlp)->getCidade()+"\nSetor:"+dynamic_cast<PessoaJuridica*>(hlp)->getSetor()+"\n";
                    }
                }
            }
            a2<<ajuste.toStdString().c_str();
            a2.close();
        }
    }
    else{
        QString caminho="";
        int tamanho = path.size()-28;//-28 = nome do arquivo executável
        for(int i=0;i<tamanho;i++)
                caminho+=path[i];
        //ABRINDO ARQUIVO
        QString local = caminho + "/Clientes.csv";
        std::ifstream ll;
        ll.open(local.toStdString());
        if(!ll.is_open()){
            std::ofstream arquivoo;
            arquivoo.open(local.toStdString());
        }
        ll.close();
    }
}
