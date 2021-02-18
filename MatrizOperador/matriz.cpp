#include "matriz.h"
namespace lia{
Matriz::Matriz(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    if(qLinhas<=0) throw QString("Quantidade de Linhas somente positiva");
    if(qColunas<=0) throw QString("Quantidade de Colunas somente positiva");
    try{
        ptMatriz = new int[qLinhas*qColunas];
    }catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}

void Matriz::setElemento(int elemento, int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

int Matriz::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

QString Matriz::getMatriz()const{
    QString saida = "";
    for(int linha = 0; linha < getQuantidadeDeLinhas(); linha++)
    {
        for(int coluna = 0; coluna < getQuantidadeDeColunas(); coluna++)
        {
            saida += QString::number(getElemento(linha,coluna));
            saida += "  ";
        }
        saida += "\n";
    }
    return saida;
}

Matriz* Matriz::operator + (Matriz const * const mat)const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) +
                        mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos adicionar as matrizes");
    }
}
Matriz* Matriz::operator-(const Matriz *const mat) const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Não pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) -
                        mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Memória insuficiente.");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar não criada. Não podemos adicionar as matrizes.");
    }
}
Matriz* Matriz::operator*(const Matriz *const mat) const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Não pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) *
                        mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Memória insuficiente.");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar não criada. Não podemos adicionar as matrizes.");
    }
}
QString Matriz::transposta(){
    QString saida = "";
    for(int linha = 0; linha < getQuantidadeDeColunas(); linha++)
    {
        for(int coluna = 0; coluna < getQuantidadeDeLinhas(); coluna++)
        {
            saida += QString::number(getElemento(coluna,linha));
            saida += "  ";
        }
        saida += "\n";
    }
    return saida;
    }
QString Matriz::multiPorConstante(int constante){
    QString saida="";
    for(int linha=0; linha<getQuantidadeDeLinhas(); linha++){
        for(int coluna=0; coluna<getQuantidadeDeColunas(); coluna++){
            saida += QString::number(getElemento(linha,coluna)*constante);
            saida += " ";
        }
        saida +="\n";
    }
    return saida;
}
bool Matriz::igualdadeEDiferenca(Matriz *mat){
    int cont=1;
    if(quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        return false;
    else{
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                if(this->getElemento(linha,coluna)==mat->getElemento(linha,coluna))
                    cont=1;
                else
                    cont+=1;
            }
        }
        if (cont==1)
            return true;
        else
            return false;
        }
}
bool Matriz::simetrica(Matriz const * const mat)const{
    for (int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if(this->getElemento(linha,coluna) != this->getElemento(coluna,linha))
                return false;
        }
    }
    return true;
}
bool Matriz::triangularSuperior(const Matriz *const mat) const{
    if(quantidadeDeLinhas != quantidadeDeColunas)
        return false;
    for(int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if(linha>coluna and this->getElemento(linha,coluna)!=0)
                return false;
        }
    }
    return true;
}
bool Matriz::triangularInferior(const Matriz *const mat) const{
    if(quantidadeDeLinhas != quantidadeDeColunas)
        return false;
    for(int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if(linha<coluna and this->getElemento(linha,coluna)!=0)
                return false;
        }
    }
    return true;
}
bool Matriz::identidade(const Matriz *const mat) const{
    if(quantidadeDeLinhas != quantidadeDeColunas)
        return false;
    for(int linha=0; linha<quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if((linha != coluna and this->getElemento(linha,coluna)!=0) or (linha == coluna and this->getElemento(linha,coluna)==0))
                return false;
        }
    }
    return true;
}
bool Matriz::ortogonal(const Matriz *const mat) const{
    if(quantidadeDeLinhas != quantidadeDeColunas)
        return false;
    Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
    for(int linha=0; linha<quantidadeDeColunas; linha++){
        for(int coluna=0; coluna<quantidadeDeLinhas; coluna++){
            int valor = this->getElemento(coluna,linha);
            aux->setElemento(valor,linha,coluna);
        }
    }
    Matriz *multi = mat->operator*(aux);
    if(multi->identidade(multi))
        return true;
    else
        return false;
}
bool Matriz::permuta(const Matriz *const mat) const{
    int x=0;
    int y=0;
    if(quantidadeDeLinhas != quantidadeDeColunas)
        return false;

    for(int linha=0; linha<quantidadeDeLinhas; linha++){
        x=0;
        y=0;
        for (int coluna=0; coluna<quantidadeDeColunas; coluna++){
            if (this->getElemento(linha,coluna)==0){
                x++;
            } else {
                if (this->getElemento(linha,coluna)==1) {
                    y++;
                } else {
                    return false;
                }
            }
        }
        if(x!=(quantidadeDeLinhas-1) or y!=1){
            return false;
        }
    }
    return true;
}
}
