//node class to hold information for characters hashtable

#ifndef list_h
#define list_h

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
        bool compareName(char * inName);
        
        //comparing power to node's data
        bool comparePower(char * inPower);
        node * next;

    private:
        
        //data being stored in each node
        char * name;
        char * power;
        char * species;
        char * desc;

};

#endif
