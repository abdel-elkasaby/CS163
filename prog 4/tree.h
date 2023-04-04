//Abdel Elkasaby, CS163
//2/13/23

//Binary Search Tree used to store characters and their information

#ifndef tree_h
#define tree_h

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

class Tree {
    public:
        //constructor and destructor
        Tree();
        ~Tree();

        //wrapper to add character to tree
        int addChar(node * inData);

        //wrapper to remove matching characters
        int remove(char * inName);

        //wrapper to retrieve matching vehicles
        int retrieve(char * inName, node **& retrieving);

        //wrapper to display all
        int displayAll();

        //wrapper to display all characters of a specific power
        int displayPower(char * inPower);

        //loading data from file
        int loadData(char * fileName);

    private:

        //recursive functions
        int addChar(node *& root, node * inData);
        int remove(char * inName, node *& root);
        int retrieve(char * inName, node**& retrieving, node * root);
        int displayAll(node * root, int level);
        int displayPower(char * inPower, node * root); 

        //adding characters to new tree based on name (sort)
        int nameAdd(node *& nameRoot, node * inData);
        //copy characters to new tree
        int copyOver(node *& nameRoot, node * root);

        node * root;

};

#endif
