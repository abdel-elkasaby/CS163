#include "stack.h"
#include "queue.h"

using namespace std;

//Abdel Elkasaby, CS163
//1/30/23

//test client for bills tracker ADT

//This program allows the user to enter data about the bill and
//store that in either a stack or a queue. The stack allows for direct
//access to the element that was most recently added, and the queue allows them
//to access the element that was added first.

int displayError(int error) { //print error messages
    
    if (error == 1)
        cout << endl << "Error: Stack is empty" << endl;
    if (error == 2)
        cout << endl << "Error: Queue is empty" << endl;
    
    return 0;
}


int main() {

    Stack stack;
    Queue queue;
   
    bool running = true;
    
    while (running) {//loop to continue prompting user until quit

        int answer = 0;

        //stack
        cout << endl << "Stack: " << endl;
        cout << "1. Add a bill (Push) " << endl;
        cout << "2. Remove most recent bill (Pop) " << endl;
        cout << "3. Display most recent bill (Peek) " << endl;
        cout << "4. Display all bills " << endl;
       
        //queue
        cout << endl << "Queue: " << endl;
        cout << "5. Add a bill (Enqueue) " << endl;
        cout << "6. Remove first bill (Dequeue) " << endl;
        cout << "7. Display first bill (Peek) " << endl;
        cout << "8. Display all bills " << endl;

        cout << endl << "9. Quit " << endl << endl;
        cout << "What would you like to do? ";

        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) { //add a bill to stack
            
            billInfo bill;
            
            bill.name = new char[1000];
            bill.desc = new char[1000];
            bill.type = new char[1000];
            bill.payment = new char[1000];

            cout << endl << "Name of the payee: ";
            cin.get(bill.name, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Bill amount: ";
            cin >> bill.amount;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Description: ";
            cin.get(bill.desc, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Type of expense: ";
            cin.get(bill.type, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Method of payment: ";
            cin.get(bill.payment, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            stack.push(bill);
            
            delete [] bill.name;
            delete [] bill.desc;
            delete [] bill.type;
            delete [] bill.payment;
        
        }

        else if (answer == 2) { //remove most recent bill
            
            displayError(stack.pop());
        }

        else if (answer == 3) { //peek at most recent bill
            
            displayError(stack.peek());
        }

        else if (answer == 4) { //display all bills

            displayError(stack.display());
        }

        else if (answer == 5) {
        
            billInfo bill;

            bill.name = new char[1000];
            bill.desc = new char[1000];
            bill.type = new char[1000];
            bill.payment = new char[1000];

            cout << endl << "Name of the payee: ";
            cin.get(bill.name, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Bill amount: ";
            cin >> bill.amount;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Description: ";
            cin.get(bill.desc, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Type of expense: ";
            cin.get(bill.type, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Method of payment: ";
            cin.get(bill.payment, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            queue.enqueue(bill);

            delete [] bill.name;
            delete [] bill.desc;
            delete [] bill.type;
            delete [] bill.payment;
        }

        else if (answer == 6) {

            displayError(queue.dequeue());
        }

        else if (answer == 7) {

            displayError(queue.peek());
        }

        else if (answer == 8) {

            displayError(queue.display());
        }

        else { //quit

            cout << endl << "Thanks for playing!" << endl << endl;
            running = false;
        }
    }

}
