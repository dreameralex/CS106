#include <iostream>
#include "c14_queue.h"
#include "c14_queue.cpp"

#include "c14_link_queue.h"
#include "c14_link_queue.cpp"


using namespace std;



int main(){
    /*
    C14_queue<int> queue;
    */
    C14_link_queue<int> queue;
    for (int i = 0 ; i < 20; i ++){
        queue.enqueue(i);
    }

    queue.print();






    return 0;
}
