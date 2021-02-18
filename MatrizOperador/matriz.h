#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>
namespace lia{
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
    Matriz* operator - (Matriz const * const mat)const;
    Matriz* operator * (Matriz const * const mat)const;
    QString transposta();
    QString multiPorConstante(int constante);
    bool igualdadeEDiferenca(Matriz *mat);
    bool simetrica(Matriz const * const mat)const;
    bool triangularSuperior(Matriz const * const mat)const;
    bool triangularInferior(Matriz const * const mat)const;
    bool identidade(Matriz const * const mat)const;
    bool ortogonal(Matriz const * const mat)const;
    bool permuta(Matriz const * const mat)const;
};
}

#endif // MATRIZ_H
