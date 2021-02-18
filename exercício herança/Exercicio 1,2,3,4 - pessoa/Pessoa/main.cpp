#include <pessoa.h>
#include <graduado.h>
#include <estudante.h>
#include <trabalhador.h>
using namespace std;
int main()
{
    Estudante estudante("20191002800950", "Ciencia da Computacao", "Area 2",
                        "Liandra de Oliveira", "Rua c14, quadra 125, lote20, Setor Sudoeste",
                        "(62)993454396", "l.o.l19@hotmail.com");
    Trabalhador trabalhador("Admistrativo", "CAE", 2.000, "Josefino", "Goiânia-GO", "(62)40028922", "josefino@gmail.com");
    Graduado graduado(2023, 2024, "123456789", "20191002800950",
                      "Ciencia da Computacao", "Area 2", "Liandra de Oliveira",
                      "Rua c14, quadra 125, lote20, Setor Sudoeste", "(62)993454396", "l.o.l19@hotmail.com");

    cout<<"ESTUDANTE: \n";
    cout<<"Matricula: "<<estudante.getMatricula();
    cout<<"\nCurso: "<<estudante.getCurso();
    cout<<"\nCampus: "<<estudante.getCampus();
    cout<<"\nNome: "<<estudante.getNome();
    cout<<"\nEndereco: "<<estudante.getEndereco();
    cout<<"\nTelefone: "<<estudante.getTelefone();
    cout<<"\nEmail: "<<estudante.getEmail()<<endl;

    cout<<"\n******************************************************************\n";
    cout<<"TRABALHADOR: ";
    cout<<"\nFuncao: "<<trabalhador.getFuncao();
    cout<<"\nDepartamento: "<<trabalhador.getDepartamento();
    cout<<"\nSalario: "<<trabalhador.getSalario();
    cout<<"\nNome: "<<trabalhador.getNome();
    cout<<"\nEndereco: "<<trabalhador.getEndereco();
    cout<<"\nTelefone: "<<trabalhador.getTelefone();
    cout<<"\nEmail: "<<trabalhador.getEmail()<<endl;

    cout<<"\n******************************************************************\n";
    cout<<"GRADUADO:" ;
    cout<<"\nAno da Conclusao: "<<graduado.getConclusao();
    cout<<"\nAno da colacao de grau: "<<graduado.getColacao();
    cout<<"\nNumero do diploma: "<<graduado.getDiploma();
    cout<<"Matricula: "<<graduado.getMatricula();
    cout<<"\nCurso: "<<graduado.getCurso();
    cout<<"\nCampus: "<<graduado.getCampus();
    cout<<"\nNome: "<<graduado.getNome();
    cout<<"\nEndereco: "<<graduado.getEndereco();
    cout<<"\nTelefone: "<<graduado.getTelefone();
    cout<<"\nEmail: "<<graduado.getEmail()<<endl;
}
