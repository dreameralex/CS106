#include "rational.h"
#include <string>
#include <cstdlib>
#include <error.h>
#include <strlib.h>
using namespace std;

int gcd(int x, int y);

Rational::Rational(){
    num = 0;
    den = 1;
}

Rational::Rational(int n){
    num = n;
    den = 1;
}

Rational::Rational(int x, int y){
    if (y==0) error("Rational: Division by zero");
    if (x==0) {
        cout << 0;
        num = 0;
        den = 1;
    }else{
        int g = gcd(abs(x), abs(y));
        num = x/g;
        den = abs(y) / g;
        if (y < 0) num = -num;
    }
}

/* show Rational */
string Rational::toString(){
    if (den == 1){
        return integerToString(num);
    }else{
        return integerToString(num) + "/" + integerToString(den);
    }
}

ostream & operator<<(ostream & os, Rational rat){
    return os << rat.toString();
}

Rational operator +(Rational r1, Rational r2){
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator -(Rational r1, Rational r2){
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator *(Rational r1, Rational r2){
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator /(Rational r1, Rational r2){
    return Rational(r1.num * r2.den, r1.den * r2.den);
}

int gcd(int x, int y){
    int r = x % y;
    while(r != 0){
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

