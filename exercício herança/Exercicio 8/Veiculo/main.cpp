#include <iostream>
#include <veiculo.h>
#include <automovel.h>
#include <aviao.h>
#include <barco.h>

int main()
{
    Automovel movel("Motocicleta", "AAA-1020", "Automovel");
    Aviao aviao("Helicoptero", "PT-MUD", "Aviao");
    Barco barco("Lancha", "----", "Barco");

    std::cout<<"AUTOMOVEL: ";
    std::cout<<"\nTipo de automovel: "<<movel.getTipoA();
    std::cout<<"\nPlaca: "<<movel.getPlaca();
    std::cout<<"\nTipo de veiculo: "<<movel.getTipoV();

    std::cout<<"\n***********************************************************\n";
    std::cout<<"AVIAO: ";
    std::cout<<"\nTipo de automovel: "<<aviao.getTipoA();
    std::cout<<"\nPlaca: "<<aviao.getPlaca();
    std::cout<<"\nTipo de veiculo: "<<aviao.getTipoV();

    std::cout<<"\n***********************************************************\n";
    std::cout<<"BARCO: ";
    std::cout<<"\nTipo de automovel: "<<barco.getTipoA();
    std::cout<<"\nPlaca: "<<barco.getPlaca();
    std::cout<<"\nTipo de veiculo: "<<barco.getTipoV()<<std::endl;
}
