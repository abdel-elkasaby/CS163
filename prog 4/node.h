//Abdel Elkasaby, CS163
//2/28/23

//Node class to hold information for characters for Binary Search Tree

#ifndef node_h
#define node_h

#include <cstring>
#include <cctype>
#include <iostream>

class node {

    public:
        
        //constructor and destructor
        node();
        ~node();

        //add data to node by passing in all args
        int addData(char * inName, char * inPower, char * inSpecies, char * inDesc);

        //add data to node by copying from node being passed in
        int addData(node * inData);

        //displaying information of node
        int display();

        //comparing name to node's data
        bool compareName(node * comparing);

        int compareName(char * inName);
        
        //comparing power to node's data
        bool comparePower(char * inPower);
 
        node * left;
        node * right;

    private:
        
        //data being stored in each node
        char * name;
        char * power;
        char * species;
        char * desc;
};

#endif
