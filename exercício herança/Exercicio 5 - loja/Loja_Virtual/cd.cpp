#include "cd.h"

CD::CD(string nomeAlbum1, string banda1, string cantor1, string genero1, int cod1, string descricao1, double preco1, string tipo1):
    Produto(cod1, descricao1, preco1, tipo1),
    nomeAlbum(nomeAlbum1),
    banda(banda1),
    cantor(cantor1),
    genero(genero1)
{

}
