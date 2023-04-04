//Abdel Elkasaby, CS163
//2/13/23

//test client for binary search tree that stores character info

#include "node.h"
#include "tree.h"

using namespace std;

int main() {

    Tree tree;
    bool running = true;

    while (running) {

        int answer;

        cout << endl << "1. Load data from a file" << endl;
        cout << "2. Add character" << endl;
        cout << "3. Display all" << endl;
        cout << "4. Display by power" << endl;
        cout << "5. Remove character" << endl;
        cout << "6. Retrieve " << endl;
        cout << "7. Quit" << endl << endl;
        cout << "What would you like to do?" << endl;
        cout << ">> ";

        cin >> answer;
        cin.clear();
        cin.ignore(1000, '\n');

        if (answer == 1) {//load from file

            char * fileName = new char[100];
            
            cout << endl << "What is the name of your file?" << endl << ">> ";
            cin.get(fileName, 100);
            cin.clear();
            cin.ignore(100, '\n');
         
            int result = tree.loadData(fileName);
            
            if (result == 1) cout << endl << "Data succesfully loaded. " << endl; 
            else if (result == -1) cout << endl << "Invalid Input." << endl;
            else if (result == 0) cout << endl << "There is no file with that name." << endl;

            delete[] fileName;

        }

        else if (answer == 2) {//add manually

            char * name = new char[100];
            char * power = new char[100];
            char * species = new char[100];
            char * desc = new char[1000];

            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the power of the character?" << endl << ">> ";
            cin.get(power, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the species of the character?" << endl << ">> ";
            cin.get(species, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Description of the character?" << endl << ">>";
            cin.get(desc, 100);
            cin.clear();
            cin.ignore(100, '\n');   

            node * hero = new node;

            int result = hero -> addData(name, power, species, desc);

            if (result == 0) cout << endl << "Invalid Input." << endl;
            else tree.addChar(hero);

            delete[] name;
            delete[] power;
            delete[] species;
            delete[] desc;
            delete hero;
        }

        else if (answer == 3) { //display all

            if (!tree.displayAll()) cout << endl << "There are no characters in the tree." << endl;
        }

        else if (answer == 4) { //display by power

            char * name = new char[100];
            char * power = new char[100];

            cout << endl << "What is the power of the character?" << endl << ">> ";
            cin.get(power, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = tree.displayPower(power);

            if (result == 0) cout << endl << "No character matches power." << endl;

            delete[] name;
            delete[] power;
        }

        else if (answer == 5) {//remove character

            char * name = new char[100];

            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = tree.remove(name);

            if (result == -1) cout << endl << "Invalid Input." << endl;
            else if (result == 0) cout << endl << "No character matches name and species." << endl;

            delete[] name;
        }

        else if (answer == 6) { //retrieve

            char * name = new char[100];

            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            node ** retrieve = new node *[1000];

            for (int i = 0; i < 1000; i++) retrieve[i] = nullptr;

            int result = tree.retrieve(name, retrieve);

            if (result == -1) cout << endl << "The tree is empty!" << endl;

            else if (result == 0) cout << endl << "No results were found" << endl;

            else {

                cout << endl << "Match found" << endl;
                cout << "Would you like to view your results? (y/n)" << endl << ">> ";

                char yesno;
                cin >> yesno;
                cin.clear();
                cin.ignore(100, '\n');

                if (yesno == 'y') {

                    for (int i = 0; i < 1000; i++)
                    {
                        if (!retrieve[i]) i = 1000;

                        else {
                            retrieve[i] -> display();
                        }
                    }

                }
            }

            for (int i = 0; i < 1000; i++) if (retrieve[i]) delete retrieve[i];
            delete[] retrieve;

            delete[] name;
        }

        else running = false;
    }

    return 0;

}
