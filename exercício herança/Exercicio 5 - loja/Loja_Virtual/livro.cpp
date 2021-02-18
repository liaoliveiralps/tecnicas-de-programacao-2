#include "livro.h"

Livro::Livro(string autor1, string tradutor1, string editora1, int ano1, int cod1, string descricao1, double preco1, string tipo1):
    Produto(cod1, descricao1, preco1, tipo1),
    autor(autor1),
    tradutor(tradutor1),
    editora(editora1),
    ano(ano1)
{

}
