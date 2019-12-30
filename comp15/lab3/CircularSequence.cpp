/*
 *      CircularSequence.cpp 
 *      PartyPlaylist 
 *      Comp 15 Lab 3
 *      Justin Steinberg
 *      2016-09-16 Created by Yennie Jun
 *      2016-09-20 Documentation added by Mark A. Sheldon, Tufts University
 */

#include <iostream>
#include <stdexcept>

#include "CircularSequence.h"


using namespace std;


/*
 * Return the index of the next element in the sequence.
 * Wraps around!
 */
int CircularSequence::nextIndex(int index)
{
        index = (index + 1)%INIT_CAPACITY;
        return index;
}


/* Default Constructor */
CircularSequence::CircularSequence()
{
        init(INIT_CAPACITY);
        size = INIT_CAPACITY;
}

/* 
 * Overloaded Constructor for a sequence with a hint for an initial
 * capacity. 
 */
CircularSequence::CircularSequence(int initialCapacity)
{
        init(initialCapacity);
}

/*
 * Initialize a new, empty sequence with an initial capacity.
 */
void CircularSequence::init(int initialCapacity)
{
        capacity      = initialCapacity;
        sequenceArray = new ElementType[capacity];
        currentSize   = 0;
        front         = 0;
        back          = 0;
}

/*
 * Destructor:  recycles the dynamically allocated array containing
 * the data.
 */
CircularSequence::~CircularSequence()
{
        delete [] sequenceArray;
}

/* 
 *  Add given element to the back of the list 
 *  Return true if element is successfully added.
 */
bool CircularSequence::addAtBack(ElementType elem) 
{
        if (currentSize == capacity) {
                expand();
        }
        sequenceArray[back] = elem;
        back                = nextIndex(back);
        currentSize++;

        return true;
}

/* 
 *  Add given element to the front of the list 
 *  Return true if element is successfully added.
 */
bool CircularSequence::addAtFront(ElementType elem)
{
        if(currentSize == capacity){
                expand();
        }        
        sequenceArray[front] = elem;
        front = nextIndex(front);
        currentSize++;

        return true;
}
                
/*
 * Remove the element at the back of the list 
 * and return it.
 */
ElementType CircularSequence::removeFromBack() 
{
        ElementType element = sequenceArray[back];
        if(front == back){ 
           front = 0;
           back = 0;
        }
        else{
           back = (back-1)%size;
        }
        return element;
}
 
/*
 * Remove the element at the front of the list 
 * and return it.
 */
ElementType CircularSequence::removeFromFront()
{
         ElementType element = sequenceArray[front];
         if(front == back){
            front = 0;
            back = 0;
         }
         else{
            front = (front+1)%size;
         }
         return element;
}

/*
 * Expand the capacity of the array by a factor of 2.
 */
void CircularSequence::expand() 
{
            size = size*2;
            ElementType * temp = new ElementType[size];
            if(front < back){
                for(int i = front; i < back; i++){
                    temp[i] = sequenceArray[i];
                }
            }
            else if(back < front){
                for(int i = back; i < front; i++){
                temp[i] = sequenceArray[i];
                }
       	    }

            delete[] sequenceArray;
            sequenceArray = temp;
}  

/*
 * Print the contents of the sequence, one element per line.
 */
void CircularSequence::printSequence() 
{
        int currIndex = front;
        for (int i = 0; i < currentSize; i++) {
                cout << sequenceArray[currIndex] << endl;
                currIndex = nextIndex(currIndex);
        }
}
