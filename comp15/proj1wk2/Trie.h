//Trie.h
//Author: Justin Steinberg
//Comp15 Project 1
//Date: March 10th, 2019
//.h file of Trie Structure
//////////////////////////////////

#ifndef TRIE_H_
#define TRIE_H_

#include <iostream>

using namespace std;

//Trie Node:

struct Node{
    bool is_end;
    Node * children[4];
    int length; 
};

class Trie{
public:

    //constructor
    Trie();

    //destructor
    ~Trie();

    Node * getNode();                   //Makes a new Node
    int insert(string key, ostream &);  //inserts a sequence
    bool search(string key);            //searches for full sequence
    void Query(string key, ostream &);  //Query's a sequence
    void print(char str[], int level, ostream &); //Prints entire Tree
    void PrefixQuery(char str[], int level, string key, ostream &); //Prefix Query
    int remove(string key, int level, ostream &);  //Removes a sequence
    void destroy(ostream &);

private:

    Node * root;   
    int count;   //Number of Nodes
    int removed;  //Number of Nodes removed
    int insert(Node * node, string key, ostream &);  //inserts node 
    bool search(Node * node, string key);            //searches for sequence
    void Query(Node * node, string key, ostream &);  //Query's sequence
    string QueryHelper(Node * node);                 //Helps Query function
    void print(Node * node, char str[], int level, ostream &);  //Prints trie
    void PrefixQuery(Node * node, char str[], int level, string key, ostream &);
    Node * remove(Node * node, string key, int level);  //removes sequence
    bool isEmpty(Node * node);              //checks if a node is empty
    void destroy(Node * node);              //destroys the trie
    void destroy(Node * node, ostream &);
};

#endif /* TRIE_H_ */
