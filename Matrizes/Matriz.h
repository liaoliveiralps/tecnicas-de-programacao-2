#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>
namespace TP2{//inicio
class Matriz
{
private:
    int quantidadeDeColunas;
    int quantidadeDeLinhas;
    int *ptMatriz;
public:
    Matriz(int qLinhas, int qColunas);
    ~Matriz(){if(ptMatriz) delete[] ptMatriz;}
    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}

    void setElemento(int elemento, int linha, int coluna)const;
    int getElemento(int linha, int coluna)const;
    QString getMatriz()const;
    Matriz* operator + (Matriz const * const mat)const;
};
}//fim


#endif // MATRIZ_H
