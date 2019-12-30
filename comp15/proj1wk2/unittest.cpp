                                
/*
 * unittest.cpp
 *
 *  Created on: March 10th, 2019
 *	Author: Justin Steinberg
 */

#include <iostream>
#include "Trie.h"

using namespace std;

int main(){

    Trie trie;
    string keys[] = {"AAA","ACG", "AGT", "AAAAT", "CGT", "TAC"};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < n; i++){
        trie.insert(keys[i]);
    }

    trie.search("AAA")? cout << "Yes\n" : cout << "No\n";
    trie.search("AAAAT")? cout << "Yes\n" : cout << "No\n";

    return 0;
}





