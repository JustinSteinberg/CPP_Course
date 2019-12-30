/*
 * main.cpp
 *
 *  Created on: March 10th, 2019
 *	Author: Justin Steinberg
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Trie.h"

using namespace std;

void read_in_query(Trie trie, string, string);

int main(int argc, char* argv[]){
    string arg1;
    string arg2;

    if(argc == 3){
        arg1 = argv[1];
        arg2 = argv[2];
    }
    else{
        cout << "Usage: ./SeqMatch [query file] [output location]" << endl;
        return 0;
    }

    Trie trie; 

    read_in_query(trie, arg1, arg2); 
    
    return 0;
}

//CREATES THE INFILES AND OUTFILES AND CHECKS THE COMMANDS//

void read_in_query(Trie trie, string filename, string filenameout)
{
    ifstream infile;
    infile.open(filename.c_str());
    if (!infile.is_open()){
        cout << "ERROR: File cannot be opened" << endl;
        return;
    }

    ofstream outfile;
    outfile.open(filenameout.c_str());
    if (!outfile.is_open()){
        cout << "ERROR: File cannot be opened\n";
        return;
    }
   
    int count = 0;
    string line;
    while (getline(infile, line))
    {
        istringstream ss(line);
        string command, key;
        ss >> command >> key;
  
        if(command == "i"){
            count = count + trie.insert(key, outfile);
        }
        else if(command == "q"){
            trie.Query(key, outfile);
        }
        else if(command == "pq"){
            char str[20];
            trie.PrefixQuery(str, 0, key, outfile);
        }
        else if(command == "r"){
            count = count - trie.remove(key, 0, outfile);     
        }
        else if(command == "n"){
            outfile << "There are " << count << " nodes in the database" << endl;
        }  
        else if(command == "p"){
            char str[20];
            trie.print(str,0,outfile);
        }
        else if(command == "d"){
            trie.destroy(outfile);
        }
     }
     infile.close();
     outfile.close();
}
