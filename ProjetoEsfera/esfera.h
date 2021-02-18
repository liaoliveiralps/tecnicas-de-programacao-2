#ifndef ESFERA_H
#define ESFERA_H

namespace lia{
class Esfera
{
private:
    float raio;
public:
    Esfera();
    float getRaio()const{return raio;}
    void setRaio(float raio){this->raio = raio;}
    float area(float raio);
    float volume(float raio);
};
}
#endif // ESFERA_H
