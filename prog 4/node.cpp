//Abdel Elkasaby, CS163
//2/13/23

//Node class implementation for characters in BST

#include "node.h"

using namespace std;

node::node() {//constructor
   
    name = nullptr;
    power = nullptr;
    species = nullptr;
    desc = nullptr;
    
    left = nullptr;
    right = nullptr;
}

node::~node() {//destructor
   
    delete[] name;
    delete[] power;
    delete[] species;
    delete[] desc;

    if (left) delete left;
    if (right) delete right;
}

//adding data to a node
int node::addData(char * inName, char * inPower, char * inSpecies, char * inDesc) {
    
    if (!inName |!inPower | !inSpecies | !inDesc) return 0;

    //copying over all strings
    name = new char[strlen(inName) + 1];
    strcpy(name, inName);

    power = new char[strlen(inPower) + 1];
    strcpy(power, inPower);

    species = new char[strlen(inSpecies) + 1];
    strcpy(species, inSpecies);

    desc = new char[strlen(inDesc) + 1];
    strcpy(desc, inDesc);

    return 1;
}

int node::addData(node * inData) {

    //copying over all strings from other node

    name = new char[strlen(inData -> name) + 1];
    strcpy(name, inData -> name);

    power = new char[strlen(inData -> power) + 1];
    strcpy(power, inData -> power);

    species = new char[strlen(inData -> species) + 1];
    strcpy(species, inData -> species);

    desc = new char[strlen(inData -> desc) + 1];
    strcpy(desc, inData -> desc);

    return 1;
}

int node::display() {

    if (!name | !power | !species | !desc) return 0;

    cout << endl << "Name: " << name << endl;
    cout << "Power: " << power << endl;
    cout << "Species: " << species << endl;
    cout << "Description: " << desc << endl;

    return 1;
}

bool node::compareName(node * comparing) {

    int comp = compareName(comparing -> name);
    
    if (comp == 0) return true;
    
    return false;
}

int node::compareName(char * inName) {

    if (strcmp(name, inName) > 0) return 0;
    else if (strcmp(name, inName) < 0); return 1;
}

bool node::comparePower(char * inPower) {

    if (strcmp(power, inPower) == 0) return true;
    
    return false;
}
