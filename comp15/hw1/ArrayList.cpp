/*
 * Array.cpp
 * COMP15
 * Spring 2019
 * Justin Steinberg
 * Implementation for Arrrrrrray of Pirates
 */

#include "ArrayList.h"
#include <iostream>
using namespace std;

// Default constructor
// Length and current position default to 0
// Creates size variable that represents the 
// size of the array 
ArrayList::ArrayList(){
    pirates = new Pirate[MAX_PIRATES];
    length = 0;
    currPos = 0;
    size = MAX_PIRATES;    
}

// Destructor
// Destroys the Dynamic Array
ArrayList::~ArrayList(){
    delete [] pirates;
}

// Inputs: Pirate object, bool by reference
// Returns: Pirate object
// Does: Looks for pirate in the array, modifies bool if found
//       Returns the object from the list and not the passed one
//       (In case they're different.)
Pirate ArrayList::find(Pirate p, bool &found) const{
    int location = 0;

    while ((location < length) && !found){
        if (p == pirates[location]){
            found = true;
            p = pirates[location];
            break;
        }
        location++;
    }
    return p;
}

// Inputs: Pirate object
// Returns: Nothing
// Does: Adds Pirate to end of array, increases length
void ArrayList::insert(Pirate p){

   if(length > 0){
      for(int i = 0; i < length; i++){
         if (pirates[i] == p){
            cout << "This pirate is already in the list" << endl;
            break;
         }
         else if(i == length-1){
            if(length >= size){
                expand();
                pirates[length] = p;
                length++;
            }
            else{
                pirates[length] = p;
                length++;
                break;
             } 
         
         }
      }   
   } 
   else{
      pirates[length] = p;
      length++;   
   }
}

// Inputs: Pirate object
// Returns: Nothing
// Does: Deletes pirate, shifts everything else over
void ArrayList::remove(Pirate p){
    if(length > 0){
        for(int i = 0; i < length; i++){
            if (pirates[i] == p){
                if(i == length - 1){
		    length--;
	            break;
	        }	
	        else{ 
                    for(; i < length - 1; i++){
                        pirates[i] = pirates[i+1];
                }            
                length--;
	        break;
                }
            }
        }          
     cout << "This Pirate is not in the List" << endl;            
     } 

     if(length < size/2){
        shrink(); 
     }   
     else{
        cout << "The List is Empty" << endl;
     }
}

// Input: None
// Returns: Pirate object
// Does: Returns pirate at currPos
//       Increments currPos, but wraps around
Pirate ArrayList::getNext(){
    Pirate p = pirates[currPos];
    currPos = (currPos + 1) % length;
    return p;
}

// Input: none
// Returns: none
// Does: sets length to 0 (memory not modified)
void ArrayList::makeEmpty(){
    length = 0;
}

// Input: none
// Returns: none
// Does: sets currPos to 0 
void ArrayList::resetArray(){
    currPos = 0;
}

// Input: none, const
// Returns: none
// Does: Prints array from 0 to length with commas 
// Inbetween names until the last name
void ArrayList::print(ofstream &outfile) const {
    for (int i = 0; i < length; i++){
        pirates[i].print(outfile);
        if( i != length-1){
           outfile << "," << " ";
        }
    } 
}

// Input: none, const
// Returns: int
// Does: Returns the value in length attribute
int ArrayList::getLength() const {
    return length;
}

// Input: none
// Returns: none
// Does: Doubes the size of the array when the capacity is reached
void ArrayList::expand(){
    
    size= size*2;
    Pirate * temp = new Pirate[size];
    for(int i = 0; i < length; i++){
        temp[i] = pirates[i];
    } 
    delete[] pirates;
    pirates = temp;
    cout << "Expand to " << size << endl;
}

// Input: none
// Returns: none
// Does: Halves the size of the array when the minimum 
// threshold is reached
void ArrayList::shrink(){

    size = size/2;
    Pirate * temp = new Pirate[size];
    for(int i = 0; i < length; i++){
        temp[i] = pirates[i];
    }
    delete[] pirates;
    pirates = temp;
    cout << "Contract to " << size << endl;
}
