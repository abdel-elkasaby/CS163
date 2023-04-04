//hashtable ADT to store characters and their info

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cmath>
#include <fstream>

//hash tabel SIZE is a prime number
const int SIZE = 23;

class table {
    public:
        //constructor and destructor
        table();
        ~table();

        //function to add character to table
        int addCharacter(char * name, char * species, node * inData);

        //function to display information of character
        int displayCharacter(char * inName, char * inSpecies);

        //function to display characters of a specific power
        int displayPower(char * inName, char * inPower);

        //display all
        bool displayAll();

        //function to load data from file
        int loadData(char * fileName);

        //wrapper and recursive functions to remove character
        int removeCharacter(char * inName, char * inSpecies);
        int removeCharacter(node *& deleting, char * inName, char * inSpecies);

        //retrieve character
        int retrieve(char * inName, node **& retrieved);

    private:

        //hash function to generate index using name and model
        int nameSpeciesHash(char * name, char * species);

        //hash table using name and species to index
        node ** nameSpeciesTable;
};
