//Abdel Elkasaby, CS163
//2/13/23

//Implementation of BST that stores characters and their info

#include "tree.h"

using namespace std;

Tree::Tree() {//constructor
    root = nullptr;
}

//destructor (deleting full tree handled by node class)
Tree::~Tree() {
    delete root;
}

//adding character (wrapper)
int Tree::addChar(node * inData) {
    return addChar(root, inData);
}

//adding character (recursive)
int Tree::addChar(node *& root, node * inData) {

    if (!root) {
        root = new node;
        root -> addData(inData);
        return 1;
    }

    if (inData -> compareName(root)) return addChar(root -> right, inData);
    return addChar(root -> left, inData); 
}

//removing character (wrapper)
int Tree::remove(char * inName) {

    if (!root) return 0;
    return remove(inName, root);
}

//finding inorder successor and shifting data
node * inOrderSuccessor(node *& root) {
    if (!root -> left) {//furthest to the left on subtree
        node * temp = root;
        if (root -> right) {
            root = root -> right;
        }
        else {
            root = nullptr;
        }
        temp -> left = nullptr;
        temp -> right = nullptr;
        return temp;
    }
    else return inOrderSuccessor(root -> left);
}


//removing character (recursive)
int Tree::remove(char * inName, node *& root) {

    if (!root) return 1;

    int comp = root -> compareName(inName);

    if (comp == 0) {//delete

        if (!root -> right && !root -> left) {//no children
            delete root;
            root = nullptr;
        }

        else if (!root -> right) {//one child left
            node * temp = root;
            root = root -> left;
            temp -> left = nullptr;
            delete temp;
            temp = nullptr;
        }

        else if (!root -> left) {//one child right
            node * temp = root;
            root = root -> right;
            temp -> right = nullptr;
            delete temp;
            temp = nullptr;
        }

        else {//two children
            node * temp = inOrderSuccessor(root -> right);
            temp -> right = root -> right;
            temp -> left = root -> left;
            root -> left = root -> right = nullptr;

            delete root;

            root = temp;
            temp = nullptr;
        }
        //go through and check subtree again
        return remove(inName, root);
    }

    else if (comp == 1) {//less
        return remove(inName, root -> left);
    }

    else if (comp == 2) {//greater
        return remove(inName, root -> right);
    }

    return 0;
}

//retrieve character (wrapper)
int Tree::retrieve(char * inName, node **& retrieving) {

    if (!root) return -1;

    return retrieve(inName, retrieving, root);
}

//retrieve character (recursive)
int Tree::retrieve(char * inName, node**& retrieving, node * root) {

    if (!root) return 0;
    int comp = root -> compareName(inName);

    if (comp == 0) {//match
        retrieving[0] = new node;
        retrieving[0] -> addData(root);
        return 1;
    }

    return 0;
}

//display all (wrapper)
int Tree::displayAll() {

    if (!root) return 0;

    return displayAll(root, 1);
}

//display all (recursive)
int Tree::displayAll(node * root, int level) {

    if (!root) return 0;

    int counter = 1;

    root -> display();
    counter += displayAll(root -> left, level+1);
    counter += displayAll(root -> right, level+1);

    return counter;
}

//display power (wrapper)
int Tree::displayPower(char * inPower) {

    if (!root) return 0;

    return displayPower(inPower, root);
}

//display power (recursive)
int Tree::displayPower(char * inPower, node * root) {

    if (!root) return 0;

    if (root -> comparePower(inPower) == true) root -> display();

    displayPower(inPower, root -> left);
    displayPower(inPower, root -> right);

    return 1;
}

//load data
int Tree::loadData(char * fileName) {

    if (!fileName) return -1;

    ifstream file;
    file.open(fileName);

    if (file) {

        char * line = new char[10000];
        char ** allInfo = new char*[4];

        //simultaneously check if next line exists and get line if it does
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

                    //memset because otherwise char array was full of junk
                    memset(allInfo[counter], 0, 1000);
                }
            }

            //make a new node with data from line
            node * adding = new node;
            adding -> addData(allInfo[0], allInfo[1], allInfo[2], allInfo[3]);

            //add node to tree
            addChar(adding);

            delete adding;
            adding = nullptr;

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

//add characters to new tree based on name (sort)
int Tree::nameAdd(node *& nameRoot, node * inData) {

    if (!nameRoot) {
        nameRoot = new node;
        nameRoot -> addData(inData);
        return 1;
    }

    if (inData -> compareName(nameRoot)) return addChar(nameRoot -> right, inData);
    return addChar(nameRoot -> left, inData); 
}

//copy character
int Tree::copyOver(node *& nameRoot, node * root) {

    if (root) nameAdd(nameRoot, root);
    if (root -> left) copyOver(nameRoot, root -> left);
    if (root -> right) copyOver(nameRoot, root -> right);

    return 1;
}

