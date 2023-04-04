//Abdel Elkasaby, CS163
//2/13/23

//test client for hashtable that stores character info

#include "node.h"
#include "table.h"

using namespace std;

int main() {
    
    table newTable;
    bool running = true;
    
    while (running) {
    
        int answer;
    
        cout << endl << "1. Load data from a file" << endl;
        cout << "2. Add character" << endl;
        cout << "3. Display all" << endl;
        cout << "4. Display by name and species" << endl;
        cout << "5. Display by power" << endl;
        cout << "6. Remove characters" << endl;
        cout << "7. Retrieve " << endl;
        cout << "8. Quit" << endl << endl;
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

            int result = newTable.loadData(fileName);
            
            if (result == -1) cout << endl << "Invalid Input." << endl;
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
            else newTable.addCharacter(name, species, hero);

            delete[] name;
            delete[] power;
            delete[] species;
            delete[] desc;
            delete hero;
        }

        else if (answer == 3) { //display all
            
            if (!newTable.displayAll()) cout << endl << "There are no characters in the table." << endl;
        }

        else if (answer == 4) { //display by name
            
            char * name = new char[100];
            char * species = new char[100];
            
            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the species of the character?" << endl << ">> ";
            cin.get(species, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.displayCharacter(name, species);
            
            if (result == 2) cout << endl << "No character matches name and species." << endl;
            else if (result == 0) cout << endl << "Invalid Input." << endl;

            delete[] name;
            delete [] species;
        }

        else if (answer == 5) { //display by power
        
            char * name = new char[100];
            char * power = new char[100];

            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the power of the character?" << endl << ">> ";
            cin.get(power, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.displayPower(name, power);

            if (result == 2) cout << endl << "No character matches power." << endl;
            else if (result == 0) cout << endl << "Invalid Input." << endl;

            delete[] name;
            delete[] power;
        }

        else if (answer == 6) {//remove character
            
            char * name = new char[100];
            char * species = new char[100];

            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the species of the character?" << endl << ">> ";
            cin.get(species, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.removeCharacter(name, species);

            if (result == -1) cout << endl << "Invalid Input." << endl;
            else if (result == 0) cout << endl << "No character matches name and species." << endl;

            delete[] name;
            delete [] species;
        }

        else if (answer == 7) { //retrieve

            node ** retrieving = new node*[1000];
            for (int i = 0; i < 1000; i++) retrieving[i] = nullptr;

            char * name = new char[100];

            cout << endl << "What is the name of the character?" << endl << ">> ";
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.retrieve(name, retrieving);

            if (result == 0) cout << endl << "No characters found with that name" << endl;
            else if (result == 1) {
                cout << endl << "Would you like to view what you retrieved (y/n)"
                    << endl << ">> ";

                char yesno;
                cin >> yesno;
                cin.clear();
                cin.ignore(100, '\n');

                if (yesno == 'y') {

                    for (int i = 0; i < 1000; i++) {

                        if (retrieving[i]) retrieving[i] -> display();
                        else break;
                    }
                }

                for (int i = 0; i < 1000; i++) {
                    if (retrieving[i]) delete retrieving[i];
                    else break;
                }

                delete[] retrieving;
            }
        }
        else running = false;
    }
    return 0;
}
