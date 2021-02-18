#include <iostream>
#include <pessoa.h>
#include <pessoafisica.h>
#include <pessoajuridica.h>

int main()
{
    PessoaFisica fisica("70306647108", "feminino", 1100, "Liandra de Oliveira",
                        "Setor Sudoeste", "(62)993454396", "l.o.l19@hotmail.com");
    PessoaJuridica juridica("11222333000181", "Minha Empresa", 150000, "Liandra",
                            "Setor Sudoeste", "(62)993454396", "l.o.l19@hotmail.com");

    cout<<"PESSOA FISICA: ";
    cout<<"\nCPF: "<<fisica.getCpf();
    cout<<"\nSexo: "<<fisica.getSexo();
    cout<<"\nRenda Bruta: R$"<<fisica.getRenda();
    cout<<"\nNome: "<<fisica.getNome();
    cout<<"\nEndereco: "<<fisica.getEndereco();
    cout<<"\nTelefone: "<<fisica.getTelefone();
    cout<<"\nEmail: "<<fisica.getEmail();
    cout<<"\nImposto de Renda: R$"<<fisica.calculoIR();

    cout<<"\n*******************************************************\n";
    cout<<"PESSOA JURIDICA: ";
    cout<<"\nCNPJ: "<<juridica.getCnpj();
    cout<<"\nRazao Social: "<<juridica.getRazaoSocial();
    cout<<"\nRenda bruta anual: "<<juridica.getRendaAnual();
    cout<<"\nNome: "<<juridica.getNome();
    cout<<"\nEndereco: "<<juridica.getEndereco();
    cout<<"\nTelefone: "<<juridica.getTelefone();
    cout<<"\nEmail: "<<juridica.getEmail();
    cout<<"\nImposto de Renda: R$"<<juridica.calculoIR()<<endl;
}
