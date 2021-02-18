#include "cubo.h"
#include <cmath>
namespace lia{
Cubo::Cubo():
    aresta(0)
{

}
float Cubo::area(float aresta){
    return pow(aresta,2)*6;
}
float Cubo::volume(float aresta){
    return pow(aresta,3);
}
}
