#include "vector.h"
#ifndef CHARSTACK_H
#define CHARSTACK_H


class CharStack{
public:
    //Empty char stack
    CharStack();

    //Frees any heap storage associated with this character stack.
    ~CharStack();

    //Retruns the number of characters in this stack.
    int size();

    //Returns true if thsi stack contains no characters.
    bool isEmpty();

    // Removes all characters from this stack.
    void clear();

    //Push
    void push(char ch);

    //Pop
    char pop();

    //Peek
    char peek();

    CharStack(const CharStack & src);

    CharStack & operator =(const CharStack & src);

    void showCharstack();

private:
    Vector<char> elements;

    static const int INITIAL_CAPACITY = 10;

    char *array;
    int capacity;
    int count;
    void deepCopy(const CharStack & src);
    void expandCapacity();

};
#endif // CHARSTACK_H
