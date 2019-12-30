//Author: Justin Steinberg          //
//Implementations of FSTreeTraversal// 
//Wed, April 10th 2019              //
//Project2, Week 1                  //
//////////////////////////////////////

#include "FSTree.h"
#include <iostream>
#include "DirNode.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#ifndef FSTREE_TRAVERSAL_H_
#define FSTREE_TRAVERSAL_H_

class FSTreeTraversal{

public:

    string Helper(DirNode * curr_node, int Depth, string s);

    void traversal(DirNode * root, int Depth);

    fstream& run_with(fstream&, int num);

    vector<string> Read_words(string file, vector<string> myVec);

    vector<string> Words;

    vector<string> Directories;

    vector<int> line_values;

private:


};


#endif
