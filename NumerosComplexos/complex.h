#ifndef COMPLEX_H
#define COMPLEX_H
#include <QString>

class Complex
{
public:
    Complex();
    void set(int real, int imaginary);
    QString get();
    Complex operator + (Complex & number) const;
    Complex operator - (Complex & number) const;
    Complex operator * (Complex & number) const;
    Complex operator / (Complex & number) const;
    bool operator == (Complex & number) const;
    void operator = (const Complex & number);
private:
    int real;
    int imaginary;
};

#endif // COMPLEX_H
