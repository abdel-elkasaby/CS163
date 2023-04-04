//Abdel Elkasaby, CS163
//3/14/23

//Test client for baking steps graph ADT

#include "graph.h"

using namespace std;

int main() {

    bool running = true;

    graph graph;

    while (running) {

        char choice;

        cout << setw(40) << setfill('-') << "" << endl;
        cout << "1. Insert Vertex" << endl;
        cout << "2. Insert onto Edge List" << endl;
        cout << "3. Display Graph" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == '1') { //insert vertex

            string step;

            cout << setw(40) << setfill('-') << "" << endl;
            cout << "Enter the step you would like to enter: ";
            cin >> step;

            if (graph.add_vertex(step) == 0) {
                cout << setw(40) << setfill('-') << "" << endl;
                cout << "Error" << endl;
            }
            else {
                cout << setw(40) << setfill('-') << "" << endl;
                cout << "Insertion Successful" << endl;
            }


        }

        else if (choice == '2') { //insert onto edge list

            string current;
            string attach;

            cout << setw(40) << setfill('-') << "" << endl;
            cout << "Enter where you would like to attach from: ";
            cin >> current;

            cout << setw(40) << setfill('-') << "" << endl;
            cout << "Enter where you would like to attach to: ";
            cin >> attach;

            if (graph.add_edge(current, attach) == 0){
                cout << setw(40) << setfill('-') << "" << endl;
                cout << "Invalid Connection" << endl;
            }
            else {
                cout << setw(40) << setfill('-') << "" << endl;
                cout << "Connection Successful" << endl;
            }
        }

        else if (choice == '3') { //display graph

            if (graph.display() == 0){
                cout << setw(40) << setfill('-') << "" << endl;
                cout << "Graph is Empty" << endl;
            }
        }

        else if (choice == '4') { //quit

            running = false;
        }

        else {
            cout << "Please Enter 1,2,3 or 4" << endl;
            cout << setw(40) << setfill('-') << "" << endl;
        }
    }

}

