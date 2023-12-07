#ifndef C14_QUEUE_H
#define C14_QUEUE_H
#include "error.h"


template <typename ValueType>
class C14_queue
{
public:
    /* Constructor: Queue
     * Usage: Queue<ValueType> queue;
     * Initializes a new empty queue.
     *
     */
    C14_queue();

    /* Destructor: ~Queue
     * Usage: (usually implicit)
     * Frees any heap storage associated with this queue.
    */
    ~C14_queue();

    /*
     * Method: size
     * Usage: int n = queue.size();
     * Return the number of values in the queue.
     * */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if (queue.isEmpty)...
     */
    bool isEmpty() const;

    /*
     * Method: clear
     * Usage: queue.clear();
     */
    void clear();

    /*
     * Method: enqueue
     * Usage: queue.enqueue(value)
     */
    void enqueue(ValueType value);

    /*
     * Method: dequeue
     * Usage: queue.dequeue(value)
     */
    ValueType dequeue();

    /*
     * Method: peek
     * Usage: queue.peek()
     */
    ValueType peek() const;

    /*
     * Method: print
     * Usage: queu.print()
     */
    void print() const;


    C14_queue(const C14_queue<ValueType> & src);
    C14_queue<ValueType> & operator=(const C14_queue<ValueType> & src);
private:
    static const int INITIAL_CAPACITY = 10;

    /* Instance variables */
    ValueType *array;
    int capacity;
    int head;
    int tail;

    /* Private method prototypes */

    void deepCopy(const C14_queue<ValueType> & src);
    void expandCapacity();

};

#endif // C14_QUEUE_H
