#include "HashNode.h"
#include <string>
#include <functional>
#include <iostream>
#include <vector>

#ifndef HASH_MAP_H_
#define HASH_MAP_H_

template<typename K, typename V>
class HashMap
{

public:

    HashMap();
        
    size_t HashCode(K key);

    void InsertNode(K key, V value, int line_value);

    V DeleteNode(K key);

    vector<V> get_value(K key);
 
    vector<int> get_lineNum(K key);    

    int sizeofMap();

    bool isEmpty();

    void display();

private:

    HashNode<K,V> ** arr;  //Hash Element Array
    size_t capacity;          //
    int size;              //Current Size

    HashNode<K,V> * dummie;
    hash<string> str_hash;

}; 

#endif
