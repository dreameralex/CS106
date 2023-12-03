#include <iostream>

#include "rational.h"
using namespace std;



int main_rational(){
    Rational a(1,2);
    Rational b(2,1);

    cout << a << endl;
    cout << a+b << endl;
    cout << a-b << endl;
    cout << a*b << endl;
    cout << a/b << endl;


    return 0;

}

