#include <bits/stdc++.h>
#include "HashNode.h"
#include "HashMap.h"
#include <iostream>
using namespace std;


int main(){

    HashMap<int, int> *h = new HashMap<int, int>;
    h->InsertNode(1,1);
    h->InsertNode(2,2);
    h->InsertNode(2,3);
    h->display();
    cout << h->sizeofMap() << endl;
    cout << h->DeleteNode(2) << endl;
    cout << h->sizeofMap() << endl;
    cout << h->isEmpty() << endl;
    cout << h->get(2);

    return 0;

}
