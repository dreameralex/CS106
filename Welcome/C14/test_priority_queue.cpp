#include <iostream>
#include "priorityqueue.h"
using namespace std;

int main_priority_queue(){
    PriorityQueue<int> queue;


    for (int i = 0 ; i < 5; i ++){
        queue.enqueue(i,2.0);
    }

    for (int i = 6 ; i < 10; i ++){
        queue.enqueue(i,1.0);
    }


    for (int i = 10 ; i < 15; i ++){
        queue.enqueue(i,4.0);
    }

    for (int i = 15 ; i < 20; i ++){
        queue.enqueue(i,3.0);
    }

    queue.enqueue(999,10.30);

    queue.enqueue(888,2.30);

    queue.print();


    queue.dequeue();

    queue.print();

    return 1;
}
