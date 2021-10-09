#pragma once
#include <iostream>
#include <string>
class Complex
{
public:
    double real;
    double im;
    Complex()
    {
        real = 0;
        im = 0;
    }
    Complex(double real, double im);
    Complex operator +(Complex);
    friend Complex operator *(Complex, Complex);
    Complex operator *=(Complex);
    void print();
    Complex cpow(Complex x, int b);
    friend Complex operator * (Complex x, Complex b)
    {
        Complex a;
        a = (x *= b);
        return a;
    }
};