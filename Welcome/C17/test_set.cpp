#include <string>
#include <vector>
#include <iostream>
#include "set_class.h"
#include "set_class.cpp"



using namespace std;

int main(){
    set_class<int> set1;
    set1.add(1);
    set1.add(2);
    set1.print();

    cout << endl << "Remove items:"<< endl;
    cout << "set1:";
    set1.remove(2);
    set1.clear();
    set1.print();


    set_class<int> set2;
    set2=set1;
    set2.add(3);
    cout << endl << "Add new set" << endl;
    cout << "set2:";
    set2.print();





    return -1;
}
