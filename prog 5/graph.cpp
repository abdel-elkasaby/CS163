//Abdel Elkasaby, CS163
//3/14/23

//ADT implementation of graph used to store data about baking steps

#include "graph.h"

using namespace std;

graph::graph() { //constructor
    
    adjacency_list = new vertex[size];

    for(int i = 0; i < size; ++i){
        adjacency_list[i].data = "";
        adjacency_list[i].head = nullptr;
    }
}

graph::~graph() { //destructor

    for(int i = 0; i < size; ++i){
        while(adjacency_list[i].head){
            node * hold = adjacency_list[i].head->next;
            delete adjacency_list[i].head;
            adjacency_list[i].head = hold;
        }
    }
    delete [] adjacency_list;
}

int graph::find(string key) { //find where to insert

    int index;
    
    for (int i = 0; i < size; ++i) {

        if (adjacency_list[i].data == key) {
            index = i;
            return index;
        }
    }
    return 0;

}

int graph::add_vertex(string step) { //insert vertex

    int key = find("");
    adjacency_list[key].data = step;
    return 1;

}

int graph::add_edge(string current, string attach) { //insert edge

    int key = find(current);
    int a_index = find(attach);

    node * edge = new node;
    edge -> adj = &adjacency_list[a_index];
    edge -> next = adjacency_list[key].head;
    adjacency_list[key].head = edge;

    return 1;
}

int graph::display() { //display all info

    for (int i = 0; i < size; ++i) {

        node * display = adjacency_list[i].head;

        cout << adjacency_list[i].data; 

        while (display) {

            cout << "->"  << display -> adj -> data; 
            display = display -> next; 

        }

        cout << endl;
    }
    return 1;
}


