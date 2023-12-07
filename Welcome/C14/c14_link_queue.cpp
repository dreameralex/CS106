#include "c14_link_queue.h"
#include <cstddef>
#include <iostream>
using namespace std;

template <typename ValueType>
C14_link_queue<ValueType>::C14_link_queue(){
    head = tail = NULL;
    count = 0;
}

template <typename ValueType>
C14_link_queue<ValueType>::~C14_link_queue(){
    clear();
}

template <typename ValueType>
C14_link_queue<ValueType>::size() const{
    return count;
}

template <typename ValueType>
bool C14_link_queue<ValueType>::isEmpty() const{
    return count == 0;
}

template <typename ValueType>
void C14_link_queue<ValueType>::clear(){
    while(count > 0)  {
        dequeue();
    }
}


template <typename ValueType>
void C14_link_queue<ValueType>::enqueue(ValueType value){
    Cell *cp = new Cell;
    cp->data = value;
    cp->link = NULL;
    if ( head == NULL){
        head = cp;
    }else{
        tail->link = cp;
    }
    tail = cp;
    count++;
}

template <typename ValueType>
ValueType C14_link_queue<ValueType>::dequeue(){
    if(isEmpty()) error("dequeue: Attempting to dequeue an empty queue");
    Cell *cp = head;
    ValueType result = cp->data;
    head = cp->link;
    if(head == NULL) tail = NULL;
    delete cp;
    count --;
    return result;
}

template <typename ValueType>
ValueType C14_link_queue<ValueType>::peek() const{
    if(isEmpty()) error("peek: Attempting to dequeue an empty queue");
    return head->data;
}

template <typename ValueType>
void C14_link_queue<ValueType>::print() const{
    Cell *cp = head;
    while (cp != NULL) {
        cout << cp->data << " ";
        cp = cp->link;
    }
}


template <typename ValueType>
C14_link_queue<ValueType>::C14_link_queue(const C14_link_queue<ValueType> & src){
    deepCopy(src);
}

template <typename ValueType>
C14_link_queue<ValueType> & C14_link_queue<ValueType>::operator =(const C14_link_queue<ValueType> & src){
    if(this != &src){
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void C14_link_queue<ValueType>::deepCopy(const C14_link_queue<ValueType> & src){
    head = NULL;
    tail = NULL;
    count = 0;
    for(Cell *cp = src.head;  cp != NULL; cp = cp->link){
        enqueue(cp->data);
    }
}



















