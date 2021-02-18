#ifndef COMPLEX_H
#define COMPLEX_H
#include <QString>
#include <cmath>
template <class A>
class Complex
{
public:
    Complex();
    void set(A real, A imaginary);
    QString get();
    Complex<A> operator + (Complex<A> & number) const;
    Complex<A> operator - (Complex<A> & number) const;
    Complex<A> operator * (Complex<A> & number) const;
    Complex<A> operator / (Complex<A> & number) const;
    bool operator == (Complex<A> & number) const;
    void operator = (const Complex<A> & number);
private:
    A real;
    A imaginary;
};
template <class A>
Complex<A>::Complex():
    real(0),
    imaginary(0)
{
}
template <class A>
void Complex<A>::set(A real, A imaginary){
    this->real=real;
    this->imaginary=imaginary;
}
template <class A>
QString Complex<A>::get(){
    QString ss;
    ss = QString::number(this->real);
    if (this->imaginary > 0)
        ss = ss + " + " + QString::number(this->imaginary);
    else
        ss = ss + QString::number(this->imaginary);
    ss = ss+"i";
    return ss;
}
template  <class A>
Complex <A> Complex<A>::operator+(Complex<A> & number)const
{
    Complex<A> num;
    num.set(number.real+this->real, number.imaginary+this->imaginary);
    return num;
}
template <class A>
Complex <A> Complex<A>::operator-(Complex<A> & number)const
{
    Complex<A> num;
    num.set(this->real-number.real, this->imaginary-number.imaginary);
    return  num;
}
template <class A>
Complex <A> Complex<A>::operator*(Complex<A> & number)const
{
    Complex<A> num;
    num.set((real*number.real)-(imaginary*number.imaginary) , (real*number.imaginary)+(imaginary*number.real));
    return  num;
}
template<class A>
Complex <A> Complex<A>::operator/(Complex<A> & number)const
{
    Complex<A> num;
    num.set( (real*number.real+imaginary*number.imaginary) / (pow(num.real,2)+pow(num.imaginary,2))  ,  (imaginary*num.real-real*num.imaginary) / (pow(num.real,2)+pow(num.imaginary,2)) );
    return num;
}
template<class A>
void Complex<A>::operator=(const Complex<A> & number)
{
    this->real= number.real;
    this->imaginary=number.imaginary;
}
template <class A>
bool Complex<A>::operator==(Complex<A> & number)const
{
    if(this->real==number.real and this->imaginary==number.imaginary)
        return true;
    else
        return false;
}
#endif // COMPLEX_H
