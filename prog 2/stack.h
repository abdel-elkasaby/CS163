#ifndef stack_h
#define stack_h

#include <iostream>
#include <cstring>
#include <cctype>

//ADT for bills (stack using LLL of arrays)

struct billInfo {
    char * name = nullptr; //name of payee
    float amount = 0; //amount of the bill
    char * desc= nullptr; //description of what it was used for
    char * type = nullptr; //type of expense
    char * payment = nullptr; //method of payment
};

struct stackNode { //each node in the stack
    billInfo * bill;
    stackNode * next;
};

const int SIZE = 5; //size of array

class Stack {
    public:
        //constructor and destructor
        Stack();
        ~Stack();

        //add bill at top of stack
        int push(billInfo toAdd);
        //remove bill from top of stack
        int pop();
        //peek at top bill in stack
        int peek();
        //wrapper funciton display all info
        int display();
    private:
        //display all bills recursively
        int display(stackNode * current, int index);
        //display single bill
        int displaySingle(billInfo toDisplay);
        //pointer to head of linked list
        stackNode * head;
        //index in the array of the top element
        int topIndex;
};

#endif
