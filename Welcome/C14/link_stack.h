#ifndef LINK_STACK_H
#define LINK_STACK_H
#include "error.h"

template <typename ValueType>
class link_stack
{
public:
    /*
    * Constructor: Stack
    * Usage: Stack<ValueType> stack;
    * Initializes a new empty stack.
    */
    link_stack();

    /*
    * Destructor: ~Stack
    * Usage: (usually implicit)
    * Frees any heap storage associated with this stack.
    */
    ~link_stack();

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
    ValueType pop();

    /*
     * Method: peek
     * Usage: C14_stack.peek()
     */
    ValueType peek() const;

    /*
     * Copy constuctor and assignment operator
     * These methods implemnet deep copying for stacks.
     */
    link_stack(const link_stack<ValueType> & src);
    link_stack<ValueType> & operator=(const link_stack<ValueType> & src);

private:
    struct Cell{
        ValueType data;
        Cell *link;
    };

    Cell *list;
    int count;

    void deepCopy(const link_stack<ValueType> &src);

};

#endif // LINK_STACK_H
