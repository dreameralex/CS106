#include "set_class.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;


template <typename ValueType>
set_class<ValueType>::set_class()
{
    /* Empty */
}

template <typename ValueType>
set_class<ValueType>::~set_class()
{
    /* Empty */
}

template <typename ValueType>
int set_class<ValueType>::size() const
{
    return map.size();
}

template <typename ValueType>
bool set_class<ValueType>::isEmpty() const
{
    return map.isEmpty();
}

template <typename ValueType>
void set_class<ValueType>::add(const ValueType & value)
{
    return map.put(value,true);
}

template <typename ValueType>
void set_class<ValueType>::remove(const ValueType & value)
{
    return map.remove(value);
}

template <typename ValueType>
bool set_class<ValueType>::contains(const ValueType & value) const
{
    return map.containsKey(value);
}

template <typename ValueType>
void set_class<ValueType>::clear()
{
    map.clear();
}

template <typename ValueType>
void set_class<ValueType>::print() const
{
    for(ValueType value:map){
        cout << value << " ";
    }
}



template <typename ValueType>
bool set_class<ValueType>::isSubsetOf(const set_class & set2)const
{
    for(ValueType value:map){
        if(!set2.contains(value)) return false;
    }
    return true;
}

template <typename ValueType>
bool set_class<ValueType>::operator ==(const set_class & set2)const{
    return isSubsetOf(set2) && set2.isSubsetOf(*this);
}

template <typename ValueType>
bool set_class<ValueType>::operator !=(const set_class & set2)const{
    return !(*this == set2);
}

template <typename ValueType>
set_class<ValueType> set_class<ValueType>::operator +(const set_class & set2)const{
    set_class<ValueType> set = *this;
    for(ValueType value: set2.map){
        set.add(value);
    }
    return set;
}

template <typename ValueType>
set_class<ValueType> set_class<ValueType>::operator +(const ValueType & value)const{
    set_class<ValueType> set = *this;
    set.add(value);
    return set;
}


template <typename ValueType>
set_class<ValueType> set_class<ValueType>::operator *(const set_class & set2)const{
    set_class<ValueType> set;
    for(ValueType value: map){
        if(set2.contains(value)) set.add(value);
    }
    return set;
}


template <typename ValueType>
set_class<ValueType> set_class<ValueType>::operator -(const set_class & set2)const{
    set_class<ValueType> set;
    for(ValueType value: map){
        if(!set2.contains(value)) set.add(value);
    }
    return set;
}

template <typename ValueType>
set_class<ValueType> set_class<ValueType>::operator -(const ValueType & value)const{
    set_class<ValueType> set = *this;
    set.remove(value);
    return set;
}

template <typename ValueType>
set_class<ValueType> & set_class<ValueType>::operator +=(const set_class & set2){
    for(ValueType value: set2.map){
        add(value);
    }
    return *this;
}

template <typename ValueType>
set_class<ValueType> & set_class<ValueType>::operator +=(const ValueType & value){
    add(value);
    return *this;
}

template <typename ValueType>
set_class<ValueType> & set_class<ValueType>::operator *=(const set_class & set2){
    Vector<ValueType> toRemove;
    for(ValueType value:map){
        if(!set2.contains(value)) toRemove.add(value);
    }
    for(ValueType value:toRemove){
        remove(value);
    }
    return *this;
}

template <typename ValueType>
set_class<ValueType> & set_class<ValueType>::operator -=(const set_class & set2){
    for(ValueType value: set2.map){
        remove(value);
    }
    return *this;
}

template <typename ValueType>
set_class<ValueType> & set_class<ValueType>::operator -=(const ValueType & value){
    remove(value);
    return *this;
}



















