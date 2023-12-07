#include "c14_queue.h"
#include <iostream>
using namespace std;
template <typename ValueType>
C14_queue<ValueType>::C14_queue(){
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    head = 0;
    tail = 0;
}

template <typename ValueType>
C14_queue<ValueType>::~C14_queue(){
    delete[] array;
}

template <typename ValueType>
int C14_queue<ValueType>::size() const{
    return (tail + capacity - head) % capacity;
}

template <typename ValueType>
bool C14_queue<ValueType>::isEmpty() const{
    return head == tail;
}

template <typename ValueType>
void C14_queue<ValueType>::clear(){
    head = tail = 0;
}

template <typename ValueType>
void C14_queue<ValueType>::enqueue(ValueType value){
    if(size() == capacity - 1) expandCapacity();
    array[tail] = value;
    tail = (tail + 1) % capacity;
}

template <typename ValueType>
ValueType C14_queue<ValueType>::dequeue(){
    if (isEmpty()) error ("dequeue: Attempting to dequeue an empty queue");
    ValueType result = array[head];
    head = (head + 1) % capacity;
    return head;
}

template <typename ValueType>
ValueType C14_queue<ValueType>::peek() const{
    if (isEmpty()) error ("peek: Attempting to dequeue an empty queue");
    return array[head];
}

template <typename ValueType>
void C14_queue<ValueType>::print() const{
    if(isEmpty()){
        cout << "Empyt Queue!";
    }else{
        cout << "The Queue is: ";
        int temp_head = head;
        int temp_end = tail;
        while((temp_head + 1) % capacity <= tail){
            cout << array[temp_head] << " ";
            temp_head++;
        }
    }
}

template <typename ValueType>
C14_queue<ValueType>::C14_queue(const C14_queue<ValueType> &src){
    deepCopy(src);
}

template <typename ValueType>
C14_queue<ValueType> & C14_queue<ValueType>::operator =(const C14_queue<ValueType> &src){
    if (this != &src){
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void C14_queue<ValueType>::deepCopy(const C14_queue<ValueType> &src){
    int count = src.size();
    capacity = count + INITIAL_CAPACITY;
    array = new ValueType[capacity];
    for (int i = 0; i < count; i++){
        array[i] = src.array[(src.head + i) % src.capacity];
    }
    head = 0;
    tail = count;
}


template <typename ValueType>
void C14_queue<ValueType>::expandCapacity(){
    int count = size();
    ValueType *oldArray = array;
    array =  new ValueType[2 * capacity];
    for (int i = 0; i < count; i ++ ){
        array[i] = oldArray[(head + i) % capacity];
    }
    capacity *= 2;
    head = 0;
    tail = count;
    delete[] oldArray;
}












