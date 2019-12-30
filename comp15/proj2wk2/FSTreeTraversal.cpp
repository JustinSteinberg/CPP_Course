//Author: Justin Steinberg          //
//Implementations of FSTreeTraversal// 
//Wed, April 10th 2019              //
//Project2, Week 2                  //
//////////////////////////////////////

#include "FSTree.h"
#include <iostream>
#include "DirNode.h"
#include <string>
#include <fstream>
#include "FSTreeTraversal.h"
#include <stdlib.h>
#include <vector>
#include "StringProcessing.h"
#include <sstream>
#include <limits>

using namespace std;

//Input: A DirNode Pointer, a Integer, and a string
//Output: A string
//Does: Returns the path of a parent directory to a child 
//directory
string FSTreeTraversal::Helper(DirNode * curr_node, int Depth, string s){

     string name = "";

     if(Depth > 0){
         
         DirNode * parent = curr_node->getParent();
           
         if(Depth > 1 || parent != NULL){ 
             string parent_name = parent->getName();
             name = parent_name + "/";
             name += s;
         }

         Depth--;
         string total = Helper(parent, Depth, name);
         return total;
     }
     else{
         return s;
     }
}

//Input: A DirNode pointer, a Integer
//Output: Nothing
//Does: Stores the directory paths in the directory vector
void FSTreeTraversal::traversal(DirNode * root, int Depth)
{
    if(root == NULL){
        return;
    }
    else if(root->hasFiles()){
        int num_files = root->numFiles();
        for(int i = 0; i < num_files; i++){
            string s = root->getFile(i);
            string dir_name = root->getName();
            if(Depth > 0){
                string dir = Helper(root, Depth, dir_name); 
             //   cout << dir << "/" << s << endl;
                dir = dir + "/" + s;
                Directories.push_back(dir);
            }
            else{
             //   cout <<  dir_name << "/" << s << endl;
                dir_name = dir_name + "/" + s;
                Directories.push_back(dir_name);
            }
        }
    }

    if(root->hasSubDir()){
        Depth++;
        int num_subdir = root->numSubDirs();
        for(int i = 0; i < num_subdir; i++){
            DirNode * Node = root->getSubDir(i);
            if(Depth > 0){
                string dir = Helper(Node, Depth, Node->getName());
             //   cout << dir << endl;
             //   Directories.push_back(dir);
            }
            traversal(Node, Depth);
        }
    }
}
//Inputs: reference to fstream file, integer
//Output: reference to fstream file
//Does: Finds the line of the word
fstream& FSTreeTraversal::run_with(fstream& file, int num){

    file.seekg(std::ios::beg);
    for(int i = 0; i < num - 1; i++){
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } 
    return file;

}

//Gets the words from a given directory path
//stores them into vectors
//returns a vector of strings
//Also counts the line number
vector<string> FSTreeTraversal::Read_words(string file, vector<string> myVec){

    ifstream infile;
    infile.open(file.c_str());
    if (!infile.is_open())
    {
     	cerr << "Could not open " << file << " for reading\n";
        return myVec;
    }
    string str;
    string line;
    StringProcessing Process;
    
    int line_value = 0;

    while(getline(infile, line)){
        line_value++;
        stringstream ss(line);
        string token;
        while(ss>>token){
            str = Process.cleanString(token);
            myVec.push_back(str);
          //  cout << "STRINGS : " << str << endl;
            line_values.push_back(line_value);
          //  cout << "LINE_VALUES : " << line_value << endl;
        }
    }

    infile.close();
   
//    for(unsigned int i = 0; i < myVec.size(); i++){
//        cout << myVec.at(i) << endl;
//    }
  
    return myVec;

}



//Main function gets path from commandline
/*int main(int argc, char* argv[]){

    int args = argc;
    if(args < 1 ){
       cout << "Please give a directory" << endl;
        return 0;
    } 

    FSTree tree = FSTree(argv[1]);

    DirNode * dirnode = tree.getRoot();
    cout << dirnode->getName() << endl;
    traversal(dirnode, 0);

    string file = "/h/jstein20/comp15/proj2wk2/test-dirs/smallGutenberg/www.gutenberg.lib.md.us/etext96/vpasm10.txt";
    
    run_with(file, "Lord");
  
}
*/
