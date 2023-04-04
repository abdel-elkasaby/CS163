//ADT implementation for hashtable storing character info

#include "table.h"

using namespace std;

table::table() {//constructor
    
    nameSpeciesTable = new node*[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        nameSpeciesTable[i] = nullptr;
    }
}

table::~table() {//destructor
    for (int i = 0; i < SIZE; i++) {
        
        if (nameSpeciesTable[i]) {
            delete nameSpeciesTable[i];
            nameSpeciesTable[i] = nullptr;
        }
    }

    delete[] nameSpeciesTable;
    nameSpeciesTable = nullptr;
}

//hash function with name and species
int table::nameSpeciesHash(char * name, char * species) {
    int index = 0;

    index += name[0];
    index += species[strlen(species) - 1];
    index = (int) pow(index, 2);
    return index % SIZE;
}

//adding a character
int table::addCharacter(char * name, char * species, node * inData) {
   
    if (!name || !species) return 0;
    
    int nameSpeciesIndex = nameSpeciesHash(name, species);

    if (!nameSpeciesTable[nameSpeciesIndex]) {//index is empty
        nameSpeciesTable[nameSpeciesIndex] = new node;
        nameSpeciesTable[nameSpeciesIndex] -> addData(inData);
    }
    else {//chaining for collision
        node * adding = nameSpeciesTable[nameSpeciesIndex];

        while (adding -> next)
            adding = adding -> next;
        
        adding -> next = new node;
        adding -> next -> addData(inData);
    }

    return 1;
}

//displaying character with certain name
int table::displayCharacter(char * inName, char * inSpecies) {
    
    if (!inSpecies) return 0;
    
    int index = nameSpeciesHash(inName, inSpecies);
    bool happened = false;
    
    node * chain = nameSpeciesTable[index];
    
    while (chain) {//traversing chain
    
        if (chain -> compareName(inName)) {
            chain -> display();
            happened = true;
        }
        
        chain = chain -> next;
    }
    
    if (happened) return 1;
    return 2;
}

int table::displayPower(char * inName, char * inPower) {

    if (!inName || !inPower) return 0;
    
    int index = nameSpeciesHash(inName, inPower);
    bool happened = false;
    
    node * chain = nameSpeciesTable[index];
    
    while (chain) {//traversing chain
    
        if (chain -> comparePower(inPower)) {
            chain -> display();
            happened = true;
        }
        
        chain = chain -> next;
    }
    
    if (happened) return 1;
    return 2;
}

//displaying entire table with index and chain (mainly for debugging)
bool table::displayAll() {
    
    bool foundAny = false;
    
    for (int i = 0; i < SIZE; i++) {//check all indices of the table
    
        if (nameSpeciesTable[i]) {
        
            foundAny = true;
            node * displaying = nameSpeciesTable[i];
            int chain = 0;
            
            while (displaying) {//checking each chain in the table
                displaying -> display();
                displaying = displaying -> next;
                chain++;
            }
            
            delete displaying;
            displaying = nullptr;
        }
    }
    return foundAny;
}

//loading data from file
int table::loadData(char * fileName) {
    
    if (!fileName) return -1;
    
    ifstream file;
    file.open(fileName);
    
    if (file) {
        char * line = new char[10000];
        char ** allInfo = new char*[7];

        //check if next line exists and get line if it does
        while (file.getline(line, 10000)) {
            allInfo[0] = new char[1000];

            memset(allInfo[0], 0, sizeof(allInfo));

            int counter = 0;
            int pos = 0;
          
            for (int i = 0; i < (int) strlen(line); i++) {
            
                if (line[i] != '|' && line[i] != '\r') {
                    allInfo[counter][pos] = line[i];
                    pos++;
                }
                
                else if (line[i] != '\r'){
                    pos++;
                    counter++;
                    pos = 0;
                    allInfo[counter] = new char[1000];

                    memset(allInfo[counter], 0, 1000);
                }
            }

            //name a new node with data from line
            node * adding = new node;
            adding -> addData(allInfo[0], allInfo[1], allInfo[2], allInfo[3]);

            //add node to table
            addCharacter(allInfo[0], allInfo[1], adding);

            delete adding;
            adding = nullptr;

            for (int i = 0; i < 7; i++) {
                delete[] allInfo[i];
                allInfo[i] = nullptr;
            }
            delete[] line;
            line = new char[10000];

            //memset again because array was full of junk
            memset(line, 0, 10000);
        }
        delete[] line;
        delete[] allInfo;
    }
    else {
        file.close();
        return 0;
    }

    file.close();
    return 1;
}

//removing character by name and power
int table::removeCharacter(char * inName, char * inSpecies) {
    
    int index = nameSpeciesHash(inName, inSpecies);
    
    if (!inName || !inSpecies) return -1;
    
    if (!nameSpeciesTable[index]) return 0;

    return removeCharacter(nameSpeciesTable[index], inName, inSpecies);
}

//recursive function to delete in chain
int table::removeCharacter(node *& deleting, char * inName, char * inSpecies) {
    
    if (!deleting) return 1;
    
    if (deleting -> compareName(inName)) {//if matches
    
        node * temp = deleting -> next;
        
        deleting -> next = nullptr;
        delete deleting;
        
        deleting = temp;
        return removeCharacter(deleting, inName, inSpecies);
    }
    
    return removeCharacter(deleting -> next, inName, inSpecies);

}

int table::retrieve(char * inName, node **&retrieved) { //retrieve character by name

    bool foundAny = false;
    int counter = 0;
    
    for (int i = 0; i < SIZE; i++) {
    
        if (nameSpeciesTable[i]) {

            node * checking = nameSpeciesTable[i];
            
            while (checking) {

                if (checking -> compareName(inName)) {

                    retrieved[counter] = new node;
                    retrieved[counter] -> addData(checking);
                    counter += 1;
                    foundAny = true;
                }

                checking = checking -> next;
            }

            delete checking;
            checking = nullptr;
        }
    }
    
    if (!foundAny) return 0;

    return 1;
}
