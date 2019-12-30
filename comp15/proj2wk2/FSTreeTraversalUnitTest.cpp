//Author: Justin Steinberg          //
//Implementations of FSTreeTraversal// 
//Wed, April 10th 2019              //
//Project2, Week 1                  //
//////////////////////////////////////

#include<FSTree.h>
#include<iostream>
#include<DirNode.h>

using namespace std;

//Input: A DirNode Pointer, a Integer, and a string
//Output: A string
//Does: Returns the path of a parent directory to a child 
//directory
string Helper(DirNode * curr_node, int Depth, string s){

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
//Does: Prints the full path of all the files
//in a given directory
void traversal(DirNode * root, int Depth)
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
                cout << dir << "/" << s << endl;
            }
            else{
                cout <<  dir_name << "/" << s << endl;
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
                cout << dir << endl;
            }
            traversal(Node, Depth);
        }
    }
}

//Main function gets path from commandline

int main(int argc, char* argv[]){

int args = argc; 

FSTree tree = FSTree(argv[1]);

DirNode * dirnode = tree.getRoot();
cout << dirnode->getName() << endl;
traversal(dirnode, 0);
}
