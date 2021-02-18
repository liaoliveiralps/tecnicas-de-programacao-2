#include <iostream>
#include <string>
using namespace std;
class Pessoa{
	public:
		Pessoa() //Construtor padrão
		{
			cout<<"Executando o construtor padrao de Pessoa"<<endl;
			idade = 0;
			peso = 0;
			nome = "";
			altura = 0;
		}
		Pessoa(string nome, int idade, float peso, float altura){ //Construtor não padrão
			this->nome = nome;
			this->idade = idade;
			this->peso = peso;
			this->altura = altura;
			cout<<"Executando o construtor nao padrao de Pessoa"<<endl;
		}
		~Pessoa() //Destrutor 
		{
			cout<<"Destruindo o objeto"<<endl;
		}
		string getNome()const{ //saber o nome da pessoa
			return nome;
		}
		void setNome(string nm){ //alterar o nome da pessoa
			this->nome = nm;
		}
		int getIdade()const{
			return idade;
		}
		void setIdade(int id){
			this->idade = id;
		}
		float getPeso()const{
			return peso;
		}
		void setPeso(float ps){
			this->peso = ps;
		}
		float getAltura()const{
			return altura;
		}
		void setAltura(float altura){
			this->altura = altura;
		}
		float getIMC()const{
			return peso/(altura*altura);
		}
	private:
		string nome;
		int idade;
		float peso;
		float altura;
};

int main()
{
	Pessoa p;
	Pessoa *pP = new Pessoa("Joaquim", 32, 56.7, 1.70);
	cout<<"Objeto foi criado"<<endl;
	p.setNome("Joao");
	p.setIdade(34);
	p.setPeso(87.4);
	p.setAltura(1.84);
	delete pP;
	cout<<"Saindo do programa"<<endl;
}
