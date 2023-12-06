#ifndef C14_STACK_H
#define C14_STACK_H
#include "error.h"

template <typename ValueType>
class C14_stack
{
public:
    /*
    * Constructor: Stack
    * Usage: Stack<ValueType> stack;
    * Initializes a new empty stack.
    */
    C14_stack();

    /*
    * Destructor: ~Stack
    * Usage: (usually implicit)
    * Frees any heap storage associated with this stack.
    */
    ~C14_stack();

    /*
     * Method: size
     * Usage: int n = C14_stack.size();
    */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if （C14_stack.isEmpty())
    */
    bool isEmpty() const;

    /*
     * Method: clear
     * Usage: C14_stack.clear()
     */
    void clear();

    /*
     * Method: push
     * Usage: C14_stack.push(value)
     */
    void push(ValueType value);

    /*
     * Method: pop
     * Usage: stack.pop(value)
     */
    void pop();

    /*
     * Method: peek
     * Usage: C14_stack.peek()
     */
    void peek() const;

    /*
     * Copy constuctor and assignment operator
     * These methods implemnet deep copying for stacks.
     */
    C14_stack(const C14_stack<ValueType> & src);
    C14_stack<ValueType> & operator=(const C14_stack<ValueType> & src);

private:
    static const int INITIAL_CAPACITY = 10;

    /* Isstace variables */
    ValueType *array;
    int capacity;
    int count;

    /* Private method prototypes */
    void deepCopy(const C14_stack<ValueType> & src);
    void expandCapacity();


};

#endif // C14_STACK_H
