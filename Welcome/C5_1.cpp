#include "vector.h"
#include "stream.h"
#include "simpio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void printVector(Vector<int> vec);

void removeZeroElements(Vector<int> & vec);

int main_5_1(){
    int n = 10;
    Vector<int> vec;
    vec.add(10);
    vec.add(20);
    vec.add(30);
    vec.add(0);
    printVector(vec);
    removeZeroElements(vec);
    printVector(vec);
    return 0;
}

void printVector(Vector<int> vec){
    cout << "[";
    for (int i = 0; i < vec.size(); i++){
        if (i > 0) cout << ", ";
        cout << vec[i];
    }
    cout << "]" << endl;
}

void removeZeroElements(Vector<int> & vec){
    for(int i = vec.size() - 1; i >= 0; i--){
        if (vec[i] == 0) vec.remove(i);
    }
}
