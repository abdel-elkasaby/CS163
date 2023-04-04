#include "stack.h"

using namespace std;

//ADT implementation for bills in stack

Stack::Stack() { //constructor
    head = nullptr;
    topIndex = 0;
}

Stack::~Stack() { //destructor

    stackNode * temp = nullptr;

    while (head) {
        
        temp = head;
        head = head -> next;
        
        for (int i = 0; i < SIZE; i++) {
            if (temp -> bill[i].name) {
                delete[] temp -> bill[i].name;
                temp -> bill[i].name = nullptr;
            }
            if (temp -> bill[i].amount) {
                temp -> bill[i].amount = 0;
            }
            if (temp -> bill[i].desc) {
                delete[] temp -> bill[i].desc;
                temp -> bill[i].desc = nullptr;
            }
            if (temp -> bill[i].type) {
                delete[] temp -> bill[i].type;
                temp -> bill[i].type = nullptr;
            }
            if (temp -> bill[i].payment) {
                delete[] temp -> bill[i].payment;
                temp -> bill[i].payment = nullptr;
            }
        }

        delete[] temp -> bill;
        temp -> bill = nullptr;
        
        temp -> next = nullptr;
        delete temp;
        
        temp = nullptr;
    }

    head = nullptr;
}

int Stack::push(billInfo toAdd) { //add bill to top of stack

    //if list doesn't exist
    if (!head) {
        head = new stackNode();
        head -> bill = new billInfo[SIZE];
    }

    //if the index is past the size of the array
    if (topIndex == SIZE) {

        stackNode * temp = head;

        head = new stackNode;
        head -> bill = new billInfo[SIZE];

        head -> next = temp;
        topIndex = 0;
    }

    //copying over data from input to stack
    head -> bill[topIndex].name = new char[strlen(toAdd.name) + 1];
    strcpy(head -> bill[topIndex].name, toAdd.name);

    head -> bill[topIndex].amount = toAdd.amount;

    head -> bill[topIndex].desc = new char[strlen(toAdd.desc) + 1];
    strcpy(head -> bill[topIndex].desc, toAdd.desc);

    head -> bill[topIndex].type = new char[strlen(toAdd.type) + 1];
    strcpy(head -> bill[topIndex].type, toAdd.type);

    head -> bill[topIndex].payment = new char[strlen(toAdd.payment) + 1];
    strcpy(head -> bill[topIndex].payment, toAdd.payment);

    ++topIndex;

    return 0;
}

int Stack::pop() { //remove first bill from stack

    //if head doesnt exist then return
    if (!head || !head -> bill[topIndex - 1].name)
        return 1;

    --topIndex;

    //index does not exist
    if (topIndex == 0) {

        stackNode * temp = head -> next;
        head -> next = nullptr;

        delete head;
        head = temp;
        topIndex = SIZE;
    }
        else {

        delete[] head -> bill[topIndex].name;
        head -> bill[topIndex].name = nullptr;

        head -> bill[topIndex].amount = 0;

        delete[] head -> bill[topIndex].desc;
        head -> bill[topIndex].desc = nullptr;

        delete[] head -> bill[topIndex].type;
        head -> bill[topIndex].type = nullptr;

        delete[] head -> bill[topIndex].payment;
        head -> bill[topIndex].payment = nullptr;

        }
    return 0;
}

int Stack::peek() { //display top bill in stack

    if (head && head -> bill[topIndex - 1].name)
        return displaySingle(head -> bill[topIndex - 1]);

    //if theres nothing to display
    return 1;
}

int Stack::display() { //wrapper function to display all bills

    if (head && head -> bill[topIndex - 1].name)
        return display(head, topIndex - 1);

    //if theres nothing left to display
    return 1;
}

int Stack::display(stackNode * current, int index) { //display all bills recursively

    //if theres nothing to display
    if (!current || !current -> bill[index].name)
        return 0; 

    displaySingle(current -> bill[index]);

    --index;

    if (index < 0) 
        return display(current -> next, SIZE - 1);

    return display(current, index);

}

int Stack::displaySingle(billInfo toDisplay) { //display a single bill

    cout << endl << "Name of the payee: " << toDisplay.name << endl;
    cout << "Amount of the bill: " << toDisplay.amount << endl;
    cout << "Description: " << toDisplay.desc << endl;
    cout << "Type of expense: " << toDisplay.type << endl;
    cout << "Method of payment: " << toDisplay.payment << endl;

    return 0;
}
