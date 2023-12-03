#include <iostream>
#include <string>
#include "vector.h"
using namespace std;



bool isPalindrome(string str);

bool isSubstringPalindrome(string str, int p1, int p2);


void main_isPalindrome(){
    string result;
    result = isPalindrome("alex");
    if (isPalindrome("aaa")){
        cout << 1 << endl;
        }else{
            cout << 0<< endl;
    }
}

bool isPalindrome(string str){
    return isSubstringPalindrome(str, 0, str.length() - 1);
}


bool isSubstringPalindrome(string str, int p1, int p2){
    if (p1 >= p2){
        return true;
    }else{
        return str[p1] == str [p2] && isSubstringPalindrome(str, p1 + 1, p2 - 1);
    }

}



int findInsortedVector(string key, Vector<string> & vec);
int binarySearch(string key, Vector<string> & vec, int p1, int p2);

void main_binarySearch(){
    Vector<string> vec;
    vec.add("a");
    vec.add("b");
    vec.add("c");
    vec.add("d");
    vec.add("e");
    vec.add("f");
    vec.add("g");

    cout << findInsortedVector("d", vec);
}


int findInsortedVector(string key, Vector<string> & vec){
    return binarySearch(key, vec, 0, vec.size() - 1);
}

int binarySearch(string key, Vector<string> & vec, int p1, int p2){
    if (p1 > p2) return -1;
    int mid = (p1 + p2) / 2;
    if (key == vec[mid]) return mid;
    if (key < vec[mid]){
        return binarySearch(key, vec, p1, mid - 1);
    }else{
        return binarySearch(key, vec, mid + 1, p2);
    }
}


bool isOdd(unsigned int n);
bool isEven(unsigned int n);

bool isOdd(unsigned int n){
    return !isEven(n);
}

bool isEven(unsigned int n){
    if (n == 0){
        return true;
    }else{
        return isOdd(n-1);
    }
}











