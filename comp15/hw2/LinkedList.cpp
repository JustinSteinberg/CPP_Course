/*
 * LinkedList.cpp
 * COMP15 HW2
 * Spring 2019
 * Justin Steinberg
 * Implementation for Linked List of Green Line Extension Stations
 */

#include "LinkedList.h"
#include "Station.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList(){
    length = 0;
    head = NULL;
    currPos = NULL;
    curr = NULL;
}

// Destructor
LinkedList::~LinkedList() {
    NodeType * ptr = head;
    NodeType * temp;
    while (ptr != NULL){
        temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l){
    NodeType *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = l.length;
    currPos = NULL;
    if (l.head == NULL)
        head = NULL;
    else{
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL){
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Input: nothing
// Returns: the length
// Does: returns the length of the LL
int LinkedList::getLength() const{
    return length;
}

// Input: nothing
// Returns: true if currPos is NULL
// Does: determines if currPos is NULL or not
bool LinkedList::isCurrPosNull() const{
    return currPos == NULL;    
}

// Input: Takes in a Station Object
// Returns: Nothing
// Does: inserts the given station to the head
// of the list, increases length of list.
void LinkedList::insertStation(Station s){
    NodeType * ptr = new NodeType;
    ptr->info = s;
    ptr->next = head;
    head = ptr;
    length++; 
}

// Input: A station object 
// Returns: Nothing
// Does: Removes the desired station from the list
// if it already exists in the list
void LinkedList::removeStation(Station s){
    NodeType *prev;
    if(head == NULL){                   //Empty List
        cout << "The list is empty";
    }
    else if(head->next == NULL){        //List is length 1
        curr = head;
        if((curr->info).isEqual(s) == true){ 
            head = NULL;
            check();
        }
        else{
            cout << "Not in List of length 1";
        }
    }
    else{                                    //If the list is longer than 1
        if((head->info).isEqual(s) == true){ //and the station is at the head
            curr = head; 
            head = head->next;
            check();
        }   
        else{                    //If the station is anywhere else in the list
            curr = head;
            while(curr->next != NULL && (curr->info).isEqual(s) == false){
                prev = curr;
                curr = curr->next;
            }
            if((curr->info).isEqual(s) == true && curr->next != NULL){
                prev->next = curr->next;
                check();
            }
            else if((curr->info).isEqual(s) == true && curr->next == NULL){
                check();
                prev->next = NULL;
            }
            else{
                cout << "Station not in list";
            }
        }     
    }             
}


// Input: Nothing
// Returns: Station Object
// Does: Gets the next station in the list
Station LinkedList::getNextStation(){
    if(length == 0){
        Station s;
        return s;
    }
    if(currPos == NULL){
       currPos = head;
    }
    else{
       currPos = currPos->next;
    }
    return currPos->info;
}

// Input: Nothing
// Returns: Nothing
// Does: Resets currPos to NULL
void LinkedList::resetCurrPos(){
   currPos = NULL;
}

// Input: Nothing 
// Returns: Nothing
// Does: deletes all elements in the list
void LinkedList::makeEmpty(){
   if(head != NULL){
       currPos = head;
       while(currPos != NULL){
           NodeType * temp = currPos->next;
           delete currPos;
           currPos = temp; 
       }
       head = NULL;
   }
   else if(head == NULL){
      cout << "List is already empty";
   }
   length = 0;
}

// Input: ostream passed by reference
// Returns: Nothing
// Does: prints every station in the list 
// along with accessibility and distance to
// the last station.
void LinkedList::print(ostream &out){
    NodeType * node = head;
    int x = length;
    while(node != NULL)
    {
        if(x > 0){
            int j = x-1;
            if(j == 0){
                (node->info).print(out);
                out << " " << j;
                node = node->next;
            }
            else if(j>0){
                (node->info).print(out);
                out << " " << j << " " << "==" << " ";
                node = node->next;
                x--;
            }
        }
        
    }   
    out << endl;
}

// Input: Nothing
// Output: Nothing
// Does: Compares curr to currPos, if they are equal
// sets currPos to NULL, then delete curr and shorten the 
// length of the array
void LinkedList::check(){
   if(curr == currPos){
       resetCurrPos();
   }
   delete curr;
   length--;
}
