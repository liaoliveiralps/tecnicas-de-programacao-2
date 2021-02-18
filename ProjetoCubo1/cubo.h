#ifndef CUBO_H
#define CUBO_H

namespace lia{
class Cubo
{
private:
    float aresta;
public:
    Cubo();
    float getAresta()const{return aresta;}
    void setAresta(float aresta){this->aresta=aresta;}
    float area(float aresta);
    float volume(float aresta);
};
}
#endif // CUBO_H
