#include "charstack.h"

#include "error.h"
#include "vector.h"
using namespace std;

CharStack::CharStack(){
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}

CharStack::~CharStack(){
    delete[] array;
}

int CharStack::size(){
    return count;
}

bool CharStack::isEmpty(){
    return count == 0;
}

void CharStack::clear(){
    count = 0;
}

void CharStack::push(char ch){
    if (count == capacity) expandCapacity();
    array[count++] = ch;
}

char CharStack::pop(){
    if(isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}

char CharStack::peek(){
    if(isEmpty()) error("pop: Attempting to peak an empty stack");
    return array[count-1];
}

void CharStack::expandCapacity(){
    char *oldArray = array;
    capacity *=2;
    array = new char[capacity];
    for (int i = 0; i < count; i++){
        array[i] = oldArray[i];
    }
    delete oldArray;
}

CharStack::CharStack(const CharStack & src){
    deepCopy(src);
}

CharStack & CharStack::operator =(const CharStack & src){
    if (this != &src){
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

void CharStack::deepCopy(const CharStack & src){
    array = new char[src.count];
    for (int i = 0; i < src.count; i++){
        array[i] = src.array[i];
    }
    count = src.count;
    capacity = src.capacity;
}

void CharStack::showCharstack(){
    for (int i = 0; i < capacity; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
