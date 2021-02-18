#include "Matriz.h"
namespace TP2{//inicio
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
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

}//fim
