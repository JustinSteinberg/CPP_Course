#include <bits/stdc++.h>
#include "HashNode.h"
#include "HashMap.h"
#include <iostream>
#include <string>

using namespace std;

template<typename K, typename V>
HashMap<K,V>::HashMap(){

    capacity = 100; 
    size = 0;
    arr = new HashNode<K,V>*[capacity];
    
    for(int i = 0; i < capacity; i++){
        arr[i] = NULL;
    }
    
    dummie = new HashNode<K,V>(-1,-1);
}

template<typename K, typename V>        
int HashMap<K,V>::HashCode(K key){
    return key % capacity;
}

template<typename K, typename V>
void HashMap<K,V>::InsertNode(K key, V value){
    HashNode<K,V> * temp = new HashNode<K,V>(key, value);
    
    int Index = HashCode(key);

    while(arr[Index] != NULL && arr[Index]->key != key && arr[Index]->key != -1)
    {
        Index++;
        Index %= capacity;
    }

    if(arr[Index] == NULL || arr[Index]->key == -1){
        size++;
    }
    
    arr[Index] = temp;

}

template<typename K, typename V>
V HashMap<K,V>::DeleteNode(int key){

    int Index = HashCode(key);
    
    while(arr[Index] != NULL)
    {
        if(arr[Index]->key == key)
        {
            HashNode<K,V> *temp = arr[Index];
            arr[Index] = dummie;
            size--;
            return temp->value;
        }
        Index++;
        Index %= capacity;
    }

    return -1;   //if it wasnt found return null

}


template<typename K, typename V>
V HashMap<K,V>::get(int key){

    int Index = HashCode(key);
    int count = 0;

    while(arr[Index] != NULL)
    {
        if(count++>capacity){
            return -1;
        }
        if(arr[Index]->key == key){
            return arr[Index]->value;
        }
        Index++;
        Index %= capacity;
    }

    return -1;

}
 
template<typename K, typename V>
int HashMap<K,V>::sizeofMap(){
    
    return size;

}

template<typename K, typename V>
bool HashMap<K,V>::isEmpty(){

    return size == 0;

}

template<typename K, typename V>
void HashMap<K,V>::display(){

    for(int i = 0; i < capacity; i++){
        if(arr[i] != NULL && arr[i]->key != -1){
            cout << "key = " << arr[i]->key << " value = " << arr[i]->value <<endl;
        }
    }

}

template class HashMap<int, int>;
//template class HashMap<double, double>;
//template class HashMap<string, string>;
//template class HashMap<string, int>;
