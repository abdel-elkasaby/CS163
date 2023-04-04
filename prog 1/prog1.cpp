#include "prog1.h"

using namespace std;

//This file will include the functions for the ADT for binge list
// Each function returns an int to show if any errors occured.
// If they return a 0, no errors.
// If they return a number 1-5, an error message will be displayed
// accordingly.

recNode::~recNode() { //destructor for recNode()

    if (recSource)
        delete recSource;
    
    recSource = NULL;
    
    if (title)
        delete title;
    
    title = NULL;
    
    if (genre)
        delete genre;
    
    genre = NULL;
}

sourceNode::~sourceNode() { //deconstructor for sourceNode()
    
    if (name)
        delete name;

    name = NULL;
}


bingeList::bingeList() { //constructor
    sourceHead == nullptr;
}

bingeList::~bingeList() { //destructor

    sourceNode * sourceTemp = nullptr;

    //deleting every source and reccomendation in list
    while (sourceHead) {

        sourceTemp = sourceHead -> sourceNext; 
        recNode * recTemp = nullptr;

        if (sourceTemp) {
            while (sourceTemp -> recHead) {

                recTemp = sourceTemp -> recHead -> recNext;

                delete sourceTemp -> recHead;
                sourceTemp -> recHead = recTemp;
            }
        }

        sourceTemp = sourceHead -> sourceNext;

        delete sourceHead;
        sourceHead = sourceTemp;

    }

    sourceHead = nullptr;
}

int bingeList::addSource(sourceNode & source) { //add a source

    sourceNode * newSource = new sourceNode;

    newSource -> name = new char[strlen(source.name) + 1];

    strcpy(newSource -> name, source.name);

    //if source list is empty, make it the head
    if (sourceHead == NULL) {
        sourceHead = newSource;
        return 0;
    }

    sourceNode * sourceTemp = sourceHead;

    //check if source already exists
    while (sourceTemp != NULL) {
        //if source already exists, dont add it
        if (strcmp(sourceTemp -> name, newSource -> name) == 0) {
            return 2;
        }

        sourceTemp = sourceTemp -> sourceNext;
    }

    sourceTemp = sourceHead;

    //traverse
    while (sourceTemp -> sourceNext != NULL) {
        sourceTemp = sourceTemp -> sourceNext;
    }

    //add source to the end of the list 
    sourceTemp -> sourceNext = newSource;


    return 0;
}

//add a reccomendation
int bingeList::addRec(recNode & rec) { 

    recNode * newRec = new recNode;

    //if source list is empty, display error
    if (sourceHead == NULL)
        return 1;

    newRec -> recSource = new char[strlen(rec.recSource) + 1];
    strcpy(newRec -> recSource, rec.recSource);

    sourceNode * sourceTemp = sourceHead;

    bool found = false;

    //check if source exists
    while (!found) {

        //if name inputted does not match one of the sources, check next
        if (!strcmp(sourceTemp -> name, newRec -> recSource) == 0) {
            sourceTemp = sourceTemp -> sourceNext;

            //source does not exist
            if (sourceTemp == NULL)
                return 3;
        }
        else
            found = true;

    }

    newRec -> title = new char[strlen(rec.title) + 1];
    strcpy(newRec -> title, rec.title);

    newRec -> genre = new char[strlen(rec.genre) + 1];
    strcpy(newRec -> genre, rec.genre);

    newRec -> seasons = rec.seasons;
    newRec -> eps = rec.eps;
    newRec -> rating = rec.rating;

    //if rec list is empty, make it the head
    if (sourceTemp -> recHead == NULL) {
        sourceTemp -> recHead = newRec;
        return 0;
    }

    recNode * recTemp = sourceTemp -> recHead;

    //traverse
    while (recTemp -> recNext != NULL) {
        recTemp = recTemp -> recNext;
    }

    //add it to the end of the list
    recTemp -> recNext = newRec;
   
    return 0;
}

int bingeList::display() { //display all sources and their recs

    //if list is empty
    if (sourceHead == NULL)
        return 1;

    sourceNode * sourceTemp = sourceHead;

    while (sourceTemp) { //display sources

        recNode * recTemp = sourceTemp -> recHead;

        cout << endl << endl << "Source name: " << sourceTemp -> name << endl;

        while (recTemp) { //display recs for each source

            cout << endl << "Show title: " << recTemp -> title << endl;
            cout << endl << "Genre: " << recTemp -> genre << endl;
            cout << endl << "Number of seasons: " << recTemp -> seasons << endl;
            cout << endl << "Number of episodes: " << recTemp -> eps << endl;
            cout << endl << "Rating: " << recTemp -> rating << endl << endl;

            recTemp = recTemp -> recNext;
        }

        sourceTemp = sourceTemp -> sourceNext;
    }

    return 0;
}

int bingeList::displaySource() { //wrapper function to display sources

    //if list is empty
    if (sourceHead == NULL)
        return 1;

    sourceNode * sourceTemp = sourceHead;

    displaySource(sourceTemp);

    return 0;
}

int bingeList::displaySource(sourceNode * sourceTemp) { //display sources recursively

    cout << endl << "Source name: " << sourceTemp -> name << endl;

    sourceTemp = sourceTemp -> sourceNext;

    if (sourceTemp != NULL)    
        displaySource(sourceTemp);

    return 0;
}

int bingeList::displayRecSource(char * inName) { //display all recs from a specific source

    //if list is empty
    if (sourceHead == NULL)
        return 1;

    sourceNode * sourceTemp = sourceHead;

    while (sourceTemp) { //loop until find name that matches input

        recNode * recTemp = sourceTemp -> recHead;

        //if the inputted name matches input
        if (strcmp(sourceTemp -> name, inName) == 0) {

            cout << endl << endl << "Source name: " << sourceTemp -> name << endl;

            while (recTemp) {

                cout << endl << "Show title: " << recTemp -> title << endl;
                cout << endl << "Genre: " << recTemp -> genre << endl;
                cout << endl << "Number of seasons: " << recTemp -> seasons << endl;
                cout << endl << "Number of episodes: " << recTemp -> eps << endl;
                cout << endl << "Rating: " << recTemp -> rating << endl << endl;

                recTemp = recTemp -> recNext;
            }
            return 0;
        }

        sourceTemp = sourceTemp -> sourceNext;
    }

    return 3; //source does not exist
}
int bingeList::displayGenre(char * inGenre) {

    //if list is empty
    if (sourceHead == NULL)
        return 1;

    sourceNode * sourceTemp = sourceHead;

    bool found = false;

    while (sourceTemp) { //loop until find name that matches input

        recNode * recTemp = sourceTemp -> recHead;

        cout << endl << endl << "Source name: " << sourceTemp -> name << endl;

        while (recTemp) {

            if (strcmp(recTemp -> genre, inGenre) == 0) {

                found = true;

                cout << endl << "Show title: " << recTemp -> title << endl;
                cout << endl << "Genre: " << recTemp -> genre << endl;
                cout << endl << "Number of seasons: " << recTemp -> seasons << endl;
                cout << endl << "Number of episodes: " << recTemp -> eps << endl;
                cout << endl << "Rating: " << recTemp -> rating << endl << endl;

            }
            recTemp = recTemp -> recNext;
        }
        sourceTemp = sourceTemp -> sourceNext;
    }

    if (found == false) //if no genres found with that name
        return 5;

    return 0;
}

int bingeList::removeSource(char * inName) {

    //if source list is empty
    if (sourceHead == NULL)
        return 1;

    sourceNode * sourceTemp = sourceHead;

    //if source to delete is the first source in list
    if (strcmp(sourceHead -> name, inName) == 0) {
        sourceHead = sourceHead -> sourceNext;
        delete sourceTemp;
        return 0;
    }

    sourceNode * sourceTemp2 = sourceHead;

    //if source to delete is not the first source
    while (sourceTemp2 -> sourceNext != NULL) {

        if (strcmp(sourceTemp2 -> sourceNext -> name, inName) == 0) {

            sourceTemp = sourceTemp2 -> sourceNext;
            sourceTemp2 -> sourceNext = sourceTemp2 -> sourceNext -> sourceNext;

            delete sourceTemp;
            return 0;
        }

        sourceTemp2 = sourceTemp2 -> sourceNext;
    }

    return 3; //source to delete does not exist
}
