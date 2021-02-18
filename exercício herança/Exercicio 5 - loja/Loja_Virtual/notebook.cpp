#include "notebook.h"

Notebook::Notebook(string marca1, string modelo1, string memoriaRAM1, string capacidadeHD1, string processador1,
                   double tamanhoTela1, int cod1, string descricao1, double preco1, string tipo1):
    Produto(cod1, descricao1, preco1, tipo1),
    marca(marca1),
    modelo(modelo1),
    memoriaRAM(memoriaRAM1),
    capacidadeHD(capacidadeHD1),
    processador(processador1),
    tamanhoTela(tamanhoTela1)
{

}
