#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
#include <iostream>

class Rational
{
public:
    Rational();
    Rational(int n);
    Rational(int x, int y);

    std::string toString();

    friend Rational operator+(Rational r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend Rational operator*(Rational r1, Rational r2);
    friend Rational operator/(Rational r1, Rational r2);

    int num;
    int den;
};
    /*
     *Overloads the << operator so that it is able to display Rational values.
    */
std::ostream & operator << (std::ostream & os, Rational pt);
Rational operator+(Rational r1, Rational r2);

Rational operator-(Rational r1, Rational r2);

Rational operator*(Rational r1, Rational r2);

Rational operator/(Rational r1, Rational r2);




#endif // RATIONAL_H
