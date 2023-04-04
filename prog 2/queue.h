#ifndef queue_h
#define queue_h

#include "stack.h"

#include <iostream>
#include <cstring>
#include <cctype>


//ADT for bills (queue using a CLL)

struct queueNode { //each node in the queue
    billInfo bill; 
    queueNode * next;
};

class Queue {
    public:
        //constructor and destructor
        Queue();
        ~Queue();

        //add bill to the rear
        int enqueue(billInfo toAdd);
        //remove bill from the top
        int dequeue();
        //peek at top bill
        int peek();
        //wrapper function to display all bills
        int display();
    private:
        //display all bills recursively
        int display(queueNode * current);
        //display single bill
        int displaySingle(billInfo toDisplay);
        //pointer for rear in CLL
        queueNode * rear;
};

#endif
