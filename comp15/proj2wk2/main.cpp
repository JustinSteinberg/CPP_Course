//Author: Justin Steinberg
//Driver for Project 2
//Comp15
//main.cpp
////////////////////////////
#include <bits/stdc++.h>
#include "HashNode.h"
#include "HashMap.h"
#include "DirNode.h"
#include "FSTree.h"
#include "FSTreeTraversal.h"
#include "StringProcessing.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <functional>
using namespace std;


int main(int argc, char* argv[]){

    int args = argc;
    if(args != 3 ){
        cerr << "Usage: ./gerp directory outputFile" << endl;
        exit(EXIT_FAILURE);
    }
    else{
        FSTree tree = FSTree(argv[1]);
    
       // cout << "made tree"<< endl;

        FSTreeTraversal Trav;

        DirNode * dirnode = tree.getRoot();
        //cout << dirnode->getName() << endl;
        Trav.traversal(dirnode, 0);
  
        HashMap<string, string> *h = new HashMap<string, string>;

       // cout << "Made Hash Node" << endl;

        //Here we Traverse through the Directories in our 
        //FSTreeTraversal class to move them into out
        //HashMap class

        for(unsigned int i = 0; i < Trav.Directories.size(); i++){
           string direct = Trav.Directories.at(i);  //gets the file
           vector<string> Wordss;                  //Vector of words from the file 
           vector<int> Line_Valuess;  
           Wordss = Trav.Read_words(direct, Wordss);  //gets words from file
           Line_Valuess = Trav.line_values;
       //    cout << "Size of Line Values: " << Line_Valuess.size() << endl;
       //    cout << "Size of Wordss: " << Wordss.size() << endl; 
           for(unsigned int j = 0; j < Wordss.size(); j++){
               h->InsertNode(Wordss.at(j), Trav.Directories.at(i), Trav.line_values.at(j)); 
           }
           Trav.line_values.clear();
        }
       
       //Open to print to outfile

       ofstream outfile;
       string OutPut_File = argv[2];
       outfile.open(OutPut_File.c_str());
       if (!outfile.is_open()){
           cerr << "Failed to open file for writing\n";
           return -1;
       }
   
       //Start Searching for Queries
  
        cout << "Query? ";
        string input;
        while(getline(cin, input)){
            cout << "Query? "; 
            if(input == "^D" || input == "@q" || input == "@quit"){
                cerr << "Goodbye! Thank you and have a nice day." << endl; 
                break; 
            }
            else{
                
                vector<string> direc = h->get_value(input);
                vector<int> line_num = h->get_lineNum(input);
          	if(line_num.size() > 1){

                    for(unsigned int j = 1; j < direc.size(); j++){
                        ifstream file(direc.at(j));
                        //Trav.run_with(file, line_num.at(j));
                        string line;
                        for(int i = 1; i <= line_num.at(j); i++){
                            getline(file, line);
                        }  
                      //  if(line_num.at(j) == line_num.at(j-1)){  
                            outfile << direc.at(0) << ":" << line_num.at(0) << ": " << line << endl;
                            break;
                      //  }
                        file.close();
                    }
                }
                else{
                   if(!direc.empty()){
                       ifstream file(direc.at(0));
                       string line;
                       for(int i = 1; i <= line_num.at(0); i++){
                           getline(file, line);
                       }  

                       outfile << direc.at(0) << ":" << line_num.at(0) << ": " << line << endl;
                       file.close();
                    }
                    else{
                        outfile << "query not found" << endl;
                    }  
                
                }
            }
        }
    
       outfile.close();
    }
    cerr << "Goodbye! Thank you and have a nice day." << endl;
    return 0;

}
