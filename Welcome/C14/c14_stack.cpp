#include "c14_stack.h"

template <typename ValueType>
C14_stack<ValueType>::C14_stack(){
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    count = 0;
}

template <typename ValueType>
C14_stack<ValueType>::~C14_stack(){
    delete[] array;
}

template <typename ValueType>
int C14_stack<ValueType>::size() const{
    return count;
}

template <typename ValueType>
bool C14_stack<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void C14_stack<ValueType>::clear(){
    count = 0;
}

template <typename ValueType>
void C14_stack<ValueType>::push(ValueType ch){
    if(count == capacity) expandCapacity();
    array[count++] = ch;
}

template <typename ValueType>
void C14_stack<ValueType>::pop(){
    if (isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}

template <typename ValueType>
void C14_stack<ValueType>::peek() const{
    if (isEmpty()) error("peek: Attempting to peet at an empty stack");
    return array[count - 1];
}

template <typename ValueType>
C14_stack<ValueType>::C14_stack(const C14_stack<ValueType> & src) {
    deepCopy(src);
}

template <typename ValueType>
C14_stack<ValueType> & C14_stack<ValueType>::operator = (const C14_stack<ValueType> & src){
    if(this != &src){
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void C14_stack<ValueType>::deepCopy(const C14_stack<ValueType> & src) {
    capacity = src.count + INITIAL_CAPACITY;
    this->array= new ValueType[capacity];
    for(int i = 0;i<src.count;i++){
        array[i] = src.array[i];
    }
    count= src.count;
}

template <typename ValueType>
void C14_stack<ValueType>::expandCapacity(){
    ValueType * oldArray = array;
    capacity *=2;
    array = new ValueType[capacity];
    for(int i = 0; i < count; i++){
        array[i] = oldArray[i];
    }
    delete[] oldArray;
}

