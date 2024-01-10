#include <iostream>
#include "map.h"
#include "error.h"
using namespace std;

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H




template <typename ValueType>
class PriorityQueue
{
public:
    /* Constructor: Queue
     * Usage: Queue<ValueType> queue;
     * Initializes a new empty queue.
     *
     */
    PriorityQueue();

    /* Destructor: ~Queue
     * Usage: (usually implicit)
     * Frees any heap storage associated with this queue.
    */
    ~PriorityQueue();

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
    void enqueue(ValueType value, double priority);

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


    PriorityQueue(const PriorityQueue<ValueType> & src);
    PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> & src);
private:
    struct Cell{
        ValueType data;
        Cell *link;
        double priority;
    };

    Cell *head;
    Cell *tail;
    int count;
    Map<double,Cell *> priority_node_tail;

    void deepCopy(const PriorityQueue<ValueType> & src);

};
#endif // PRIORITYQUEUE_H


template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(){
    head = tail = NULL;
    count = 0;
}

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue(){
    clear();
}

template <typename ValueType>
PriorityQueue<ValueType>::size() const{
    return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const{
    return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear(){
    while(count > 0)  {
        dequeue();
    }
}





template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority){
    Cell *cp = new Cell;
    cp->data = value;
    cp->link = NULL;
    cp->priority = priority;

    if (priority_node_tail.containsKey(priority)){
        Cell *temp_priority = new Cell;
        temp_priority = priority_node_tail.get(priority);
        cp->link = temp_priority->link;
        temp_priority->link = cp;
        priority_node_tail.put(priority,cp);
    }else{
        Vector<double> keys;
        keys = priority_node_tail.keys();
        keys.sort();
        double before_prioirty;
        double after_prioirty;
        for (int i = 0; i < keys.size(); i++){
            if (keys[i] <= priority){
                before_prioirty = keys[i];
            }else{
                after_prioirty = keys[i];
            }
        }
        Cell *before_priority_cell = new Cell;
        before_priority_cell = priority_node_tail.get(before_prioirty);

        if(before_priority_cell == NULL){
            if (head == NULL){
                head = cp;
            }else{
                Cell *temp_head = new Cell;
                temp_head->data = head->data;
                temp_head->priority = head->priority;
                temp_head->link = head->link;


                cp->link = temp_head;
                head = cp;
            }

        }else{
            cp->link = before_priority_cell->link;
            before_priority_cell->link = cp;
        }

        priority_node_tail.put(priority,cp);


    }
    if(tail ==NULL){
        cout << 2;
        tail = cp;
    }else{
        while(tail->link != NULL){
            tail = tail->link;
        }
    }
    count++;

}




template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue(){
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
ValueType PriorityQueue<ValueType>::peek() const{
    if(isEmpty()) error("peek: Attempting to dequeue an empty queue");
    return head->data;
}

template <typename ValueType>
void PriorityQueue<ValueType>::print() const{
    Cell *cp = head;
    while (cp != NULL) {
        cout << "(" << cp->data << ", " << cp->priority << ") ";
        cp = cp->link;
    }
}


template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> & src){
    deepCopy(src);
}

template <typename ValueType>
PriorityQueue<ValueType> & PriorityQueue<ValueType>::operator =(const PriorityQueue<ValueType> & src){
    if(this != &src){
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType> & src){
    head = NULL;
    tail = NULL;
    count = 0;
    for(Cell *cp = src.head;  cp != NULL; cp = cp->link){
        enqueue(cp->data);
    }
}
