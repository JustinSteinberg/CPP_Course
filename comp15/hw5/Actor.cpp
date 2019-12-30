#include "Actors.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

Actor::Actor(){
    name = "NoName";
    movie = "NoMovie";
}

Actor::Actor(string input_name, string input_movie){
    name = input_name;
    movie = input_movie;
}

void Actor::insert_movie(string input_movie){

    bool found = false;
    input_movie == movies.find(input_movie, found);
    if(found == false){ 
        movies.insert(input_movie);
    }
}

void Actor::insert_name(string input_name){
   
    name = input_name;
}

bool Actor::get_movie(string input_movie){
    bool found = false;
    input_movie = movies.find(input_movie, found);
    return found;
}

LinkedList<string> Actor::get_list(){

    return movies;
}

string Actor::get_name(){

    return name;
}

string Actor::connect(Actor A){
    
    LinkedList<string> A_movies = A.get_list(); 
    int length1 = A_movies.get_length();

    for(int i = 0; i < length1; i++){
        string s = A_movies.get_value_at(i);
        if(get_movie(s) == true){
            return s;
        }
    }
    return "";
}
 
bool operator == (const Actor &a, const Actor &b){

    return (a.name == b.name);
}

bool operator != (const Actor &a, const Actor &b){
    
    return !(a.name == b.name);
}

ostream &operator << (ostream &out, const Actor &a){

    out << a.name << endl;
}
