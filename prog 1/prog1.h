#include <iostream>
#include <cstring>
#include <cctype>

//Abdel Elkasaby, CS163
//1/17/23

//This will manage a binge list class with sources and shows.

struct recNode {
    ~recNode();
    char * recSource; //source of this reccomendation
    char * title; //show title
    char * genre; //genre type
    int seasons; //# of seasons
    int eps; //total # of episodes
    int rating; //star rating
    recNode * recNext; //next reccomendation in list
};

struct sourceNode {
    ~sourceNode();
    char * name; //source name
    recNode * recHead; //first reccomendation under this source
    sourceNode * sourceNext; //next source in list
};

class bingeList {
    public:
        //constructor, initialize data members to zero
        bingeList();
        //destructor, deallocate dynamic memory
        ~bingeList(); 
        //add source
        int addSource(sourceNode & source); 
        //add a reccomendation from a specfic source
        int addRec(recNode & rec); 
        //display all reccomendations 
        int display();
        //wrapper function to display all sources
        int displaySource();
        //display all recs from a specific source
        int displayRecSource(char * inName);
        //display all recs of a specific genre
        int displayGenre(char * inGenre);
        //remove a specific source
        int removeSource(char * inName);
    private:
        //display all sources recursively
        int displaySource(sourceNode * sourceTemp);
        sourceNode * sourceHead; //head pointer for first source
};
