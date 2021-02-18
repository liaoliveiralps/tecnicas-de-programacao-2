#ifndef VEICULO_H
#define VEICULO_H
#include <string>
using std::string;

class Veiculo
{
protected:
    string placa;
    string tipoVeiculo;
public:
    Veiculo(string placa, string tipoVeiculo);
    string getPlaca(){return placa;}
    void setPlaca(string placa){this->placa=placa;}
    string getTipoV(){return tipoVeiculo;}
    void setTipoV(string tipo){tipoVeiculo=tipo;}
};

#endif // VEICULO_H
