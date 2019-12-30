//Author: Justin Steinberg
//Comp15
//Proj2 
//HashMap.cpp implementation

#include "HashNode.h"
#include "HashMap.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;
//Constructor for hash table
template<typename K, typename V>
HashMap<K,V>::HashMap(){

    capacity = 400000; 
    size = 0;
    arr = new HashNode<K,V>*[capacity];
    
    for(unsigned int i = 0; i < capacity; i++){
        arr[i] = NULL;
    }
    
    dummie = new HashNode<K,V>("","");
}
//HashFunction for strings
//Converts string into int
template<typename K, typename V>        
size_t HashMap<K,V>::HashCode(K key){
    size_t value = 0;
    value = str_hash(key);
    return value % capacity;
}

//Inserts hashNode Into HashTable
template<typename K, typename V>
void HashMap<K,V>::InsertNode(K key, V value, int line_value){


    size_t Index = HashCode(key);


    if(arr[Index] != NULL && arr[Index]->key == key){
        arr[Index]->values.push_back(value);
        arr[Index]->line_values.push_back(line_value);
    }

    else{

     //   cout << "In the else statement " << endl;

        HashNode<K,V> * temp = new HashNode<K,V>(key, value);

      //  cout << "Made Temp Node" << endl;

     //   cout << "KEY : " << key << endl;

        while(arr[Index] != NULL && arr[Index]->key != key && arr[Index]->key != "")
        {
            Index++;
            Index = Index % capacity;
      //    cout << "INDEX IN WHILE LOOP: " << Index << endl;
        }

     //   cout << "Got through the while loop " << endl;

        if(arr[Index] == NULL || arr[Index]->key == ""){
            size++;
        }
    
    //    cout << "Adding to arr " << endl;

        arr[Index] = temp;
        arr[Index]->line_values.push_back(line_value);
    //    cout << "Added to arr " << "Index: " << Index << " Key: " << arr[Index]->key << endl;

    } 

}
//Deletes a hashNode
template<typename K, typename V>
V HashMap<K,V>::DeleteNode(K key){


    size_t Index = HashCode(key);

    
    if(arr[Index]->key == key && arr[Index]->values.size() > 1){
  

        arr[Index]->values.pop_back();
        arr[Index]->line_values.pop_back();
        return arr[Index]->value;
    }

    else{

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
            Index = Index % capacity;
        }

    return "";   //if it wasnt found return null

    }

}

//Return the vector of values in HashNode
template<typename K, typename V>
vector<V> HashMap<K,V>::get_value(K key){

    size_t Index = HashCode(key);
    size_t count = 0;

    while(arr[Index] != NULL)
    {
        if(count++>capacity){
            return {};
        }
        if(arr[Index]->key == key){
            return arr[Index]->values;
        }
        Index++;
        Index %= capacity;
    }

    return {};

}
//Returns Vector of ints from HashNode 
template<typename K, typename V>
vector<int> HashMap<K,V>::get_lineNum(K key){

    size_t Index = HashCode(key);
    size_t count = 0;

    while(arr[Index] != NULL)
    {
     	if(count++>capacity){
            return {};
        }
	if(arr[Index]->key == key){
            return arr[Index]->line_values;
        }
	Index++;
        Index %= capacity;
    }

    return {};

}


//Gets the size of the Hash Table
template<typename K, typename V>
int HashMap<K,V>::sizeofMap(){
    
    return size;

}

//Checks is hash table is empty
template<typename K, typename V>
bool HashMap<K,V>::isEmpty(){

    return size == 0;

}

//displays the entire hash table
template<typename K, typename V>
void HashMap<K,V>::display(){

   for(unsigned int i = 0; i < capacity; i++){
       if(arr[i] != NULL && arr[i]->key != ""){
           for(unsigned int j = 0; j < arr[i]->values.size(); j++){

               cout << "key = " << arr[i]->key << " value = " << arr[i]->values.at(j) << "Line #: " << arr[i]->line_values.at(0) << endl;
           }
       }
   }

}

//template class HashMap<int, int>;
//template class HashMap<double, double>;
template class HashMap<string, string>;
//template class HashMap<string, int>;
