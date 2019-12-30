//Trie.cpp
//Author: Justin Steinberg
//Comp15 HW3
//Date: March 12th, 2019
//Implementation of Trie Structure
//////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include "Trie.h"

using namespace std;

//Constructor
Trie::Trie()
{
    root = NULL;
    count = 0;
    removed = 0;
}

//Destructor
Trie::~Trie(){
   // destroy(root);      //There are two destroys so this one doesnt need
}                         //to pass in an outfile

//Second destory function to print to outfile 
void Trie::destroy(ostream &out){
    destroy(root, out);
    out << "There are 0 nodes in the database" << endl;
    root = NULL;
}

//Input: A pointer to a node
//output: nothing
//does: destorys the entire trie
void Trie::destroy(Node * node){

    for(int i = 0; i < 4; i++){
        if(node->children[i] != NULL){
            destroy(node->children[i]);
        }
    }
    delete node;
}

//delete function deletes entire trie
void Trie::destroy(Node * node, ostream &out){
    for(int i = 0; i < 4; i++){
        if(node->children[i] != NULL){
            destroy(node->children[i], out);
        }
    }
    delete node;
    if(count > 0){
        count--;
    }
}

//Input: Nothing
//Output: A new Node
//Does: Creates a new node
Node * Trie::getNode(){

    Node * new_node = new Node();
    new_node->is_end = false;
    for(int i = 0; i < 4; i++){
        new_node->children[i] = NULL; 
    }
    return new_node;
}


//Input:A string and a reference to an outfile
//Output: An integer which counts the nodes
//Does: calls the private insert function 
int Trie::insert(string key, ostream &out)
{
    if(root == NULL){
       root = getNode();
    }
    return insert(root, key, out);
}

//Input: Pointer to a node, string, and reference to an outfile
//Output: An integer
//Does: Inserts a sequence into the Trie and prints it to outfile
int Trie::insert(Node * node, string key, ostream &out){
    
    if(search(key) == true){
        out << key << " was previously inserted" << endl;
        return 0;
    }
    else{
        Node * curr = node;
        int index = 0;
        for(int i = 0; i < (int)key.length(); i++){
        
            if(key[i] == 'A'){
                index = 0;
            }
            else if(key[i] == 'C'){
                index = 1;
            }
            else if(key[i] == 'G'){
                index = 2;
            }
            else if(key[i] == 'T'){
                index = 3;
            }
            if(curr->children[index] == NULL){
                curr->children[index] = getNode();
                count++;
            }
            curr = curr->children[index];

        }
        curr->is_end = true;  //Mark end of word
        curr->length = key.length();
        out << key << " inserted" << endl;
    }
    return count;
}

//Input: string
//Output: bool
//Does: calls the private search function
// (starts from root)
bool Trie::search(string key)
{
     if(root == NULL){
         return false;
     }
     return search(root, key);
}

//Input: reference to node, string
//Output: boolean
//Does: checks if a sequence is in the trie
bool Trie::search(Node * node, string key){
    Node * curr = node;
    int index = 0;
    for(int i = 0; i < (int)key.length(); i++){
       if(key[i] == 'A'){
            index = 0;
        }
	else if(key[i] == 'C'){
            index = 1;
        }
	else if(key[i] == 'G'){
            index = 2;
        }
	else if(key[i] == 'T'){
            index = 3;
        }

        if(curr->children[index] == NULL){
            return false;
        }
        curr = curr->children[index];
    }
    
    return (curr != NULL && curr->is_end);
}

//Input: string, reference to ostream
//Output: nothing
//Does:checks if root is null, prints to outfile, calls the
//private query function
void Trie::Query(string key, ostream &out){
    if(root != NULL){
        Query(root, key, out);
    }
    else{
        out << key << ": No match found" << endl;
    }
}
  
//Input: Reference to Node, string, reference to ostream
//Output: nothing
//Does: Checks the prefix of a sequence to a sequence in the trie
void Trie::Query(Node * node, string key, ostream &out){
    Node * curr = node;
    if(search(key) == true){
        out << "Match found: " << key << " 100%" << endl;
    }
    else{
        string seq = "";
        int pref = 0;
        int index = 0;
        int len = 0;
        for(int i = 0; i < (int)key.length(); i++){
           if(key[i] == 'A'){
                index = 0;
            }
	    else if(key[i] == 'C'){
                index = 1;
            }
	    else if(key[i] == 'G'){
                index = 2;
            }
	    else if(key[i] == 'T'){
                index = 3;
            }

	    if(curr->children[index] != NULL){
                pref++;
                seq += key[i];
                curr = curr->children[index];      
            }
            else{
                break;
            }
        }
        if(pref >= 1){
            seq.append(QueryHelper(curr));
            if(seq.length() >= key.length()){
                len = seq.length();
            }
            else if(seq.length() < key.length()){
                len = key.length();
            }
            double match = 100*((double)pref/(double)len);
            out << "Match found: " << seq << " " << round(match) << "%" << endl;  
        }   
        else{
            out << key << ": No match found" << endl;
        }
    }
}

//Input: Reference to a node
//Output: A string
//Does: Concatinates the remaining characters in a sequence
// from the trie if the sequence is longer than the key
string Trie::QueryHelper(Node * curr){

    int prev_index = 0;
    string seq = "";

    while(curr != NULL){
        if(curr->children[0] != NULL){
            curr = curr->children[0];
            seq += 'A';
            prev_index = 0;
            if(curr->is_end == true){
                break;
            }
        }
        else if(curr->children[1] != NULL){
  	    curr = curr->children[1];
            seq += 'C';
            prev_index = 1;   
            if(curr->is_end == true){
                break;
            }          
       	}
        else if(curr->children[2] != NULL){
       	    curr = curr->children[2];
            seq += 'G';
            prev_index = 2;
            if(curr->is_end == true){
                break;
            }
       	}
        else if(curr->children[3] != NULL){
       	    curr = curr->children[3];
            seq += 'T';
            prev_index = 3;
            if(curr->is_end == true){
                break;
            }
       	}
        else{
            break;
        }
    }
    return seq;                    
}

//Input: array of chars, integer, reference to ostream
//Output: nothing 
//Does: calls the private print function
void Trie::print(char str[], int level, ostream &out){
    if(root != NULL){
        print(root, str, level, out);
    }
}


//Input: Reference to Node, array of chars, int, reference to ostream
//Output: nothing
//Does: prints all the sequences in the trie
void Trie::print(Node * node, char str[], int level, ostream &out){
    
    if(node->is_end == true){
        str[level] = '\0';
        out << str << endl;
    }
    int x = 0;
    for(int i = 0; i < 4; i++){
        if(node->children[i] != NULL){
            if(i == 1){
                x = 2;
            }
            else if(i == 2){
                x = 6;
            }
            else if(i == 3){
                x = 19;
            } 
            else{
                x = 0;
            }  
            str[level] = x + 'A';
            print(node->children[i], str, level + 1, out);
        }
    }
}
//Input:array of chars, string, reference to ostream
//Output: nothing
//Does:checks if root is null, calls private PrefixQuery
void Trie::PrefixQuery(char str[], int level, string key, ostream &out){
    if(root != NULL){
        PrefixQuery(root, str, level, key, out);
    }
    else{
        out << key << ": No match found" << endl;
    }
}

//Input: Reference to node, array of chars, string reference to out
//Output: Nothing
//Does: Checks if the prefix of a sequence already in the trie
// matches the sequence provided
void Trie::PrefixQuery(Node * node, char str[], int level, string key, ostream &out){

    if(node->is_end == true){
        bool is_pref = false;
        str[level] = '\0';
        if(key.length() <= strlen(str)){
            for(int i = 0; i < (int)key.length(); i++){
                if(key[i] == str[i]){
                    is_pref = true;
                }
                else{
                    is_pref = false;
                    break;
                }
            }
        }
        if(is_pref == true){
            out << str << endl;
        }      
    }

    int x;
    for(int i = 0; i < 4; i++){
        if(node->children[i] != NULL){
            if(i == 1){
                x = 2;
            }
            else if(i == 2){
                x = 6;
            }
            else if(i == 3){
                x = 19;
            }
            else{
                x = 0;
            }
            str[level] = x + 'A';
            PrefixQuery(node->children[i], str, level + 1, key, out);
        }
    }
}

//Input:A reference to a node
//Output: Boolean
//Does: Checks if a node is empty
bool Trie::isEmpty(Node * node){
    for(int i = 0;i<4;i++){
        if(node->children[i] != NULL){
            return false;
        }
    }
    return true;
}

//Input:String, Int, reference to outfile
//Output: Integer
//Does: checks if sequence is in the trie, class remove
int Trie::remove(string key, int level, ostream &out){
    if(search(key) == false){
        out << key << ": No match found" << endl;
        return 0;
    }
    else{
        remove(root, key, level);
        out << key << " " << "removed " << endl;
        return removed;
    }
}

//Input: reference to a node, string, int
//Output: A reference to a node
//Does: Removes node from the trie
Node * Trie::remove(Node * node, string key, int level){
    if(root == NULL){
        return NULL;
    }
    if(level == (int)key.size()){
        if(node->is_end == true){
            node->is_end = false;
        }
        if(isEmpty(node) == true){
           delete node;
           node = NULL;
           removed++;
        }

        return node;
    }

    int index = key[level] - 'A';
    int x = 0;
    if(index == 2){        //C
        x = 1;
    }
    else if(index == 6){   //G
        x = 2;
    }
    else if(index == 19){  //T
        x = 3;
            }
    else{                  //A
        x = 0;
    }

    node->children[x] = remove(node->children[x], key, level + 1);

 //   if(isEmpty(node) == false){
 //       if(node->is_end == false){
 //           delete node; 
 //           node = NULL;
 //           removed++;
 //       }
 //    }
    return node;
}
 
