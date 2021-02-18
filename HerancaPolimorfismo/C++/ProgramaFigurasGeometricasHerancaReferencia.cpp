#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class FiguraGeometrica
{
    public:
		FiguraGeometrica(float r=0 ):raio(r){};
		float obterRaio() {return raio;};  // Normal
		void atribuirRaio(float r ) {raio = r;}; // Normal
		virtual float areaTotal() = 0; // Virtual Pura
		virtual float volume() = 0; // Virtual Pura
		virtual string tipoFigura() = 0; // Virtual Pura
    protected:
		float raio;
};

class Esfera : public FiguraGeometrica
{
    public:
// chamando construtor pai
		Esfera(float r=0) : FiguraGeometrica(r) {}; 

//polimorfismo de sobreposicao por substituicao
//obrigatorio porque na classe FiguraGeometrica este sao Vituais Puros
		float areaTotal() {return 4*3.14*raio*raio; }; 
		float volume(){return ((float)4/3)*3.14*raio*raio*raio;}; 
		string tipoFigura() { return "Esfera";};
    
};

class Cilindro : public FiguraGeometrica
{
    public:
// chamando construtor pai e inicializando o atributo
		Cilindro (float r, float a) : FiguraGeometrica(r), altura(a) {};

//polimorfismo de sobreposicao por substituicao
//obrigatorio porque na classe FiguraGeometrica este sao Vituais Puros
		float areaTotal() {return 2*3.14*raio*(altura+raio);};
		float volume() {return 3.14*raio*raio*altura;};
		string tipoFigura() {return "Cilindro";};

// Métodos Normais
		float obterAltura() {return altura;};  // Normal
		void atribuirAltura(float a) {altura = a;}; // Normal

// Método Virtual
		virtual float areaLateral() {return 2*3.14*raio*altura;}; // Virtual

    protected:
		float altura;
};


class Cone : public Cilindro
{
    public:
// chamando construtor pai
		Cone(float r, float a) : Cilindro(r,a) {};

//polimorfismo de sobreposicao por substituicao
//obrigatorio porque na classe FiguraGeometrica este sao Vituais Puros
		float areaTotal() {return 3.14*raio*(geratriz()+raio);};
		string tipoFigura() {return "Cone";};
		float areaLateral() { return 3.14*raio*geratriz();};

//polimorfismo de sobreposicao por refinamento
		float volume() {return 1.0/3.0 * Cilindro::volume();}; 
	
// Método Normal	
		float geratriz() {return sqrt((altura*altura)+(raio*raio));};
};

void imprimirObjeto(FiguraGeometrica &obj){
  	cout<<endl<<"***  Metodo Imprimir Objeto  ***";
    cout<<endl<<"Figura: "<<obj.tipoFigura();
	cout<<endl<<"Raio: "<<obj.obterRaio()<<endl;
    	cout << "Area Total: " << obj.areaTotal() << endl;
    	cout << "Volume: " << obj.volume() << endl ;
    cout<<"**********************************"<<endl;//064 35128067
}

int main(void)
{

//Instancia das Classes Esfera, Cilindro e Cone;
    Esfera objetoEsfera(5);
    Cilindro objetoCilindro(5,5);
    Cone objetoCone(3,4);

// Tratamento do Objeto Esfera
	imprimirObjeto(objetoEsfera);

// Acesso aos elementos do objetoCilindro
    imprimirObjeto(objetoCilindro);
    cout<<"Areal Lateral: "<<objetoCilindro.areaLateral()<<endl ;// do Filho

// Acesso aos elementos do objetoCone
    imprimirObjeto(objetoCone);
    cout<<"Areal Lateral: "<<objetoCone.areaLateral()<<endl ;
    cout<<"Geratriz: "<<objetoCone.geratriz()<<endl ;
}

