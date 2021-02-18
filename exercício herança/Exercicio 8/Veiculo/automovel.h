#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H
#include <veiculo.h>

class Automovel : public Veiculo
{
protected:
    string tipoAutomovel;
public:
    Automovel(string tipoAutomovel1, string placa1, string tipoVeiculo1);
    string getTipoA(){return tipoAutomovel;}
    void setTipoA(string tipo){tipoAutomovel=tipo;}
};

#endif // AUTOMOVEL_H
