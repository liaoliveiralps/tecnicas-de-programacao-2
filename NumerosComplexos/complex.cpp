#include "complex.h"
#include <cmath>
Complex::Complex()
{

}
void Complex::set(int real, int imaginary){
    this->real=real;
    this->imaginary=imaginary;
}

QString Complex::get(){
    QString ss;
    ss = QString::number(this->real);
    if (this->imaginary > 0)
        ss = ss + " + " + QString::number(this->imaginary);
    else
        ss = ss + QString::number(this->imaginary);
    ss = ss+"i";
    return ss;
}

Complex Complex::operator + (Complex & number) const{
    Complex num;
    num.set(number.real+this->real, number.imaginary+this->imaginary);
    return num;
}
Complex Complex::operator-(Complex &number) const{
    Complex num;
    num.set(this->real-number.real, this->imaginary-number.imaginary);
    return  num;
}
Complex Complex::operator*(Complex &number) const{
    Complex num;
    num.set((real*number.real)-(imaginary*number.imaginary) , (real*number.imaginary)+(imaginary*number.real));
    return  num;
}
Complex Complex::operator/(Complex &number) const{
    Complex num;
    num.set( (real*number.real+imaginary*number.imaginary) / (pow(num.real,2)+pow(num.imaginary,2))  ,  (imaginary*num.real-real*num.imaginary) / (pow(num.real,2)+pow(num.imaginary,2)) );
    return num;
}
void Complex::operator = (const Complex & number){
    this->real= number.real;
    this->imaginary=number.imaginary;
}
bool Complex::operator==(Complex &number) const{
    if(this->real==number.real and this->imaginary==number.imaginary)
        return true;
    else
        return false;
}
