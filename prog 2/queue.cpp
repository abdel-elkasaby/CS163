#include "queue.h"

using namespace std;

//ADT implementation for bills in queue

Queue::Queue() { //constructor
    rear = nullptr;
}

Queue::~Queue() { //destructor

    while (rear && rear != rear -> next) {
        
        queueNode * temp = rear -> next;
        rear -> next = temp -> next;
        
        if (temp -> bill.name)
            delete temp -> bill.name;
        
        if (temp -> bill.amount)
            temp -> bill.amount = 0;
        
        if (temp -> bill.desc)
            delete temp -> bill.desc;
        
        if (temp -> bill.type)
            delete temp -> bill.type;
        
        if (temp -> bill.payment)
            delete temp -> bill.payment;

        delete temp;
        temp = nullptr;
    }

    if (rear) {

        if (rear -> bill.name)
            delete rear -> bill.name;

        if (rear -> bill.amount)
            rear -> bill.amount = 0;

        if (rear -> bill.desc)
            delete rear -> bill.desc;
        
        if (rear -> bill.type)
            delete rear -> bill.type;

        if (rear -> bill.payment)
            delete rear -> bill.payment;
        
        delete rear; 
        rear = nullptr; 
    }
}

int Queue::enqueue(billInfo toAdd) { //add bill to the end of the queue

    //if list doesn't exist yet
    if (!rear) {
        
        rear = new queueNode;

        rear -> bill.name = new char[strlen(toAdd.name) + 1];
        strcpy(rear -> bill.name, toAdd.name);

        rear -> bill.amount = toAdd.amount;

        rear -> bill.desc = new char[strlen(toAdd.desc) + 1];
        strcpy(rear -> bill.desc, toAdd.desc);

        rear -> bill.type = new char[strlen(toAdd.type) + 1];
        strcpy(rear -> bill.type, toAdd.type);

        rear -> bill.payment = new char[strlen(toAdd.payment) + 1];
        strcpy(rear -> bill.payment, toAdd.payment);

        rear -> next = rear;

        return 0;
    }

    //adding new element to list
    queueNode * temp = new queueNode;
       
    temp -> bill.name = new char[strlen(toAdd.name) + 1];
    strcpy(temp -> bill.name, toAdd.name);

    temp -> bill.amount = toAdd.amount;

    temp -> bill.desc = new char[strlen(toAdd.desc) + 1];
    strcpy(temp -> bill.desc, toAdd.desc);

    temp -> bill.type = new char[strlen(toAdd.type) + 1];
    strcpy(temp -> bill.type, toAdd.type);

    temp -> bill.payment = new char[strlen(toAdd.payment) + 1];
    strcpy(temp -> bill.payment, toAdd.payment);

    temp -> next = rear -> next;
    rear -> next = temp;
    rear = temp;

    return 0;
}

int Queue::dequeue() { //remove bill from the top of queue

    //if rear doesn't exist can't dequeue
    if (!rear)
        return 2;

    //if theres only one bill in list
    if (rear == rear -> next) {
        delete rear;
        rear = nullptr;

        return 0;
    }

    //delete first item in list
    queueNode * temp = rear -> next;
    rear -> next = rear -> next -> next;

    delete temp;
    temp = nullptr;

    return 0;
}

int Queue::peek() { //peek at next bill in queue

    if (rear && rear -> bill.name)
        return displaySingle(rear -> next -> bill);

    //if theres nothing to display
    return 2;
}

int Queue::display() { //wrapper function to display bills

    if (rear) {
        return display(rear -> next);
    }

    return 2;
}

int Queue::display(queueNode * current) { //display bills recursively

    //if theres nothing to display
    if (!current || !current -> bill.name)
        return 2;

    displaySingle(current -> bill);

    if (current != rear) 
        return display(current -> next);

    return 0;
}

int Queue::displaySingle(billInfo toDisplay) { //display single bill

    cout << endl << "Name of the payee: " << toDisplay.name << endl;
    cout << "Amount of the bill: " << toDisplay.amount << endl;
    cout << "Description: " << toDisplay.desc << endl;
    cout << "Type of expense: " << toDisplay.type << endl;
    cout << "Method of payment: " << toDisplay.payment << endl;

    return 0;
}
