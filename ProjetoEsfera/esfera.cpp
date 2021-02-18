#include "esfera.h"
#include <cmath>
namespace lia{
Esfera::Esfera():
    raio(0)
{

}
float Esfera::area(float raio){
    return 4*3.14*raio*raio;
}
float Esfera::volume(float raio){
    return (4*3.14*pow(raio,3)/3);
}
}
