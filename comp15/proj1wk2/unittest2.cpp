*
 * unittest2.cpp
 *
 *  Created on: March 10th, 2019
 *	Author: Justin Steinberg
 */

#include <iostream>
#include "Trie.h"

using namespace std;

int main(){

    Trie trie;
    string keys[] = {"AAA","ACG", "AGT", "AAAAT", "CGT", "TAC", "AGT"};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < n; i++){
        trie.insert(keys[i]);
    }

    trie.search("AAA")? cout << "Yes\n" : cout << "No\n";
    trie.search("AAAAT")? cout << "Yes\n" : cout << "No\n";

    trie.Query("A");
    trie.Query("CAT");

    int level = 0;
    char str[20];
    cout << "Contents of the Trie: " << endl;
    trie.print(str, level);


    cout<<"Prefix Query: " << endl;
    trie.PrefixQuery(str, level, "A");

    cout << "Removal: " << endl;
    trie.remove("AAA",0);

    trie.search("AAA")? cout << "Yes\n" : cout << "No\n";


    return 0;

}
