#include "link_stack.h"
#include <cstddef>
#include "strlib.h"
#include <iostream>
using namespace std;

template <typename  ValueType>
link_stack<ValueType>::link_stack(){
    list = NULL;
    count = 0;
}

template <typename  ValueType>
link_stack<ValueType>::~link_stack(){
    clear();
}

template <typename  ValueType>
int link_stack<ValueType>::size() const{
    return count;
}

template <typename  ValueType>
bool link_stack<ValueType>::isEmpty() const{
    return count == 0;
}

template <typename  ValueType>
void link_stack<ValueType>::clear(){
    while(count >0){
        pop();
    }
}

template <typename  ValueType>
void link_stack<ValueType>::push(ValueType value){
    Cell *cp =  new Cell;
    cp->data = value;
    cp->link = list;
    list = cp;
    count ++;
}

template <typename  ValueType>
ValueType link_stack<ValueType>::pop(){
    if(isEmpty()) error("pop: Attempting to pop an empty stack");
    Cell *cp = list;
    ValueType result = cp->data;
    list = list->link;
    count --;
    delete cp;
    return result;
}

template <typename  ValueType>
ValueType link_stack<ValueType>::peek() const{
    if(isEmpty()) error("pook: Attempting to peek an empty stack");
    return list->data;
}

template <typename  ValueType>
link_stack<ValueType> &  link_stack<ValueType>::operator=(const link_stack<ValueType> & src){
    if (this != &src){
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename  ValueType>
void link_stack<ValueType>::deepCopy(const link_stack<ValueType> & src){
    count = src.count;
    Cell *tail = NULL;
    for (Cell *cp = src.list; cp != NULL; cp = cp->link){
        Cell *ncp = new Cell;
        ncp->data = cp->data;
        if(tail == NULL){
            list = ncp;
        }else{
            tail->link = ncp;
        }
        tail = ncp;
    }
    if (tail != NULL) tail->link = NULL;
}








