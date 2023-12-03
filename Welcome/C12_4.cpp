#include <iostream>
#include "charstack.h"
using namespace std;


int main_c12_4(){
    CharStack a;

    a.push('a');
    cout << a.peek() << endl;
    a.pop();

    cout << "Size: " << a.size() << endl;
    for (int i = 0; i< 20; i++){
        //cout << "push " << i << endl;
        a.push('a');
    }
    a.showCharstack();

    cout << "Size: " << a.size() << endl;
    cout << "peek: " << a.peek() << endl;


    CharStack b;

    b = a;

    a.showCharstack();

    b.pop();
    b.push('c');
    b.showCharstack();





    return 0;

}
