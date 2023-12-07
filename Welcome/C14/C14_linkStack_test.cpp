#include <iostream>
#include "link_stack.h"
#include "link_stack.cpp"
using namespace std;



int main_c14_link_stack(){
    link_stack<int> A;
    A.push(1);
    A.push(2);
    cout << A.peek();

    return 0;
}
