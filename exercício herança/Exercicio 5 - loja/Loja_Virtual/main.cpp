#include <produto.h>
#include <livro.h>
#include <cd.h>
#include <notebook.h>
using namespace std;

int main()
{
    Livro livro("Markus Zusak", "Vera Ribeiro", "Intriseca", 2008, 001, "A menina que roubava livros", 39.99, "Livro");
    CD cd("Shawn Mendes [Deluxe]", "Shawn Mendes", "Shawn Mentes", "POP Internacional",
          002, "CD Shawn Mendes - International Version Deluxe", 35.9, "CD de musica");
    Notebook note("Lenovo", "Ideapad S1450", "8GB", "1TB", "Intel Core i5 - 8th Gen",
                  15.6, 003, "Notebook Lenovo Ideapad S145", 2.745, "Notebook");

    cout<<"LIVRO: \n";
    cout<<"Autor: "<<livro.getAutor();
    cout<<"\nTradutor: "<<livro.getTradutor();
    cout<<"\nEditora: "<<livro.getEditora();
    cout<<"\nAno de publicacao: "<<livro.getAno();
    cout<<"\nCodigo: "<<livro.getCod();
    cout<<"\nDescricao: "<<livro.getDescricao();
    cout<<"\nPreco: "<<livro.getPreco();
    cout<<"\nTipo de produto: "<<livro.getProd();

    cout<<"\n*************************************************************\n";
    cout<<"CD: ";
    cout<<"\nNome do album: "<<cd.getAlbum();
    cout<<"\nBanda: "<<cd.getBanda();
    cout<<"\nCantor: "<<cd.getCantor();
    cout<<"\nGenero: "<<cd.getGenero();
    cout<<"\nCodigo: "<<cd.getCod();
    cout<<"\nDescricao: "<<cd.getDescricao();
    cout<<"\nPreco: "<<cd.getPreco();
    cout<<"\nTipo de produto: "<<cd.getProd();

    cout<<"\n*************************************************************\n";
    cout<<"NOTEBOOK: ";
    cout<<"\nMarca: "<<note.getMarca();
    cout<<"\nModelo: "<<note.getModelo();
    cout<<"\nMemoria RAM: "<<note.getMemoria();
    cout<<"\nCapacidade do HD: "<<note.getHD();
    cout<<"\nProcessador: "<<note.getProcessador();
    cout<<"\nTamanho da tela: "<<note.getTamanhoTela();
    cout<<"\nCodigo: "<<note.getCod();
    cout<<"\nDescricao: "<<note.getDescricao();
    cout<<"\nPreco: "<<note.getPreco();
    cout<<"\nTipo de produto: "<<note.getProd()<<endl;
}
