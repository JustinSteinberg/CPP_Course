 //Implementation of the actor class

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

#ifndef ACTOR_H_
#define ACTOR_H_ 

class Actor
{
public:

    Actor();                     //constructor
    Actor(string, string);       //paramaterized constructor
    void insert_movie(string);   //inserts movie into linkedlist
    void insert_name(string);    //inserts name into an actor object
    bool get_movie(string);      //determines if actor was in movie
    string connect(Actor);       //determines if actor has movies in common
    LinkedList<string> get_list();      //returns the linked list of movies
    string get_name();           //returns name of actor
    friend bool operator == (const Actor &, const Actor &);
    friend bool operator != (const Actor &, const Actor &);
    friend ostream &operator << (ostream &, const Actor &);

private:
  
    string name;  
    string movie;
    LinkedList<string> movies; 
};

#endif

