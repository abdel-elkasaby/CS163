//Abdel Elkasaby, CS163
//3/14/23

//Graph used to store data about baking steps

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

struct vertex {
    std::string data;
    struct node * head;
};

struct node {
    vertex * adj;
    node * next;
};

class graph {

    public:

        //constructor and destructor
        graph();
        ~graph();

        int add_vertex(std::string step); //insert vertex
        int add_edge(std::string current, std::string attach); //insert edge
        int find(std::string key); //find where to insert
        int display(); //display all

    private:
        vertex * adjacency_list;
        int size = 5;
};

