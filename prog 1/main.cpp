#include "prog1.h"

using namespace std;

// Test client for binge list ADT

int displayError(int error);

int displayError(int error) {

    if (error == 1)
        cout << endl << "Error: Source list is empty" << endl;
    else if (error == 2)
        cout << endl << "Error: Source already exists" << endl;
    else if (error == 3)
        cout << endl << "Error: Source does not exist" << endl;
    else if (error == 4)
        cout << endl << "Error: No reccomendations found from that source" << endl;
    else if (error == 5)
        cout << endl << "Error: No genres found with that name" << endl;

    return 0;
}

int main() {
   
    bingeList list;
    sourceNode source;
    recNode rec;

    bool running = true;

    while (running) {//loop to continue prompting user until quit
        
        int answer = 0;
       
        cout << endl << "1. Add a source " << endl;
        cout << "2. Add a reccomendation " << endl;
        cout << "3. Display all info " << endl;
        cout << "4. Display all sources " << endl;
        cout << "5. Display all recs from a source " << endl;
        cout << "6. Display all recs from a genre " << endl;
        cout << "7. Remove a source " << endl;
        cout << "8. Quit " << endl << endl;
        cout << "What would you like to do? "; 

        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) { //add a source
            
            source.name = new char[1000];

            cout << endl << "Source name? ";
            cin.get(source.name, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            displayError(list.addSource(source));
        }
        
        else if (answer == 2) { //add a reccomendation
            
            rec.recSource = new char[1000];
            rec.title = new char[1000];
            rec.genre = new char[1000];

            cout << endl << "Which source recommended this show? ";
            cin.get(rec.recSource, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Title? ";
            cin.get(rec.title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
        
            cout << endl << "Genre? ";
            cin.get(rec.genre, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Number of seasons? ";
            cin >> rec.seasons;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Number of episodes? ";
            cin >> rec.eps;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Rate it out of 10: ";
            cin >> rec.rating;
            cin.clear();
            cin.ignore(100, '\n');
            
            displayError(list.addRec(rec));
        }

        else if (answer == 3) { //display all info
           
            displayError(list.display());
        }

        else if (answer == 4) {
            
            displayError(list.displaySource());
        }
        
        else if (answer == 5) { //display all recs from a specific source

            char * inName = new char[1000];

            cout << endl << "Source to display? ";
            cin.get(inName, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n'); 

            displayError(list.displayRecSource(inName));
            
            delete inName;
            inName = NULL;
        }
        
        else if (answer == 6) { //display all recs from a specific genre
            
            char * inGenre = new char[1000];

            cout << endl << "Genre to display? ";
            cin.get(inGenre, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            
            displayError(list.displayGenre(inGenre));
            
            delete inGenre;
            inGenre = NULL;
        }

        else if (answer == 7) { //remove a source
            
            char * inName = new char [1000];

            cout << endl << "Source to remove? ";
            cin.get(inName, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            displayError(list.removeSource(inName));
        
            delete inName;
            inName = NULL;
        }

        else { //quit
           
            cout << endl << "Thanks for playing!" << endl << endl;
            running = false;
        }
    }
}
