#include "Complex.h"
#include <iostream>
using namespace std;
Complex::Complex(double creal, double cim)
{
    real = creal;
    im = cim;
}

Complex Complex:: operator +(Complex x)
{
    Complex a;
    a.real = x.real + real;
    a.im = x.im + im;
    return a;
}

void Complex::print()
{
    if ((im != 0) && (real != 0))
    {
        if (im < 0) cout << real << im << "i";
        else cout << real << "+" << im << "i";
    }
    else if (im == 0)
        cout << real;
    else if (real == 0)
        cout << im << "i";
    return;
}

Complex Complex:: operator *= (Complex a)
{
    double r1 = real;
    real = a.real * real - a.im * im;
    im = a.real * im + a.im * r1;
    return *this;
}

Complex Complex::cpow(Complex x, int b)
{
    Complex a = x;
    int i;
    for (i = 0; i < b - 1; ++i)
        x *= a;
    return x;
}

