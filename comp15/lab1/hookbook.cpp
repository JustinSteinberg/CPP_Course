//  Justin Steinberg
//  01/16/19
//  Lab1
//  Comp15

#include <iostream>
#include "ArrayList.h"
#include "Pirate.h"
using namespace std;

const int x = 698;

void More_Pirates(ArrayList arr){

  ifstream infile;
  infile.open("pirate_names.txt");
  if(!infile.is_open()){
          cerr << "file could not open";
  }
  
    for(int j = 0; j < 5; j++){
        Pirate p;
        p.assign_pirate_id();
        p.generate_pirate_name(infile, x);
        p.print();
        arr.insert_pirate(p);
        if(arr.is_full() == true)
        {
            break;
        }
    }
  Pirate p;
  p.assign_pirate_id();
  p.generateNextPirate(infile);
  p.print();

 // arr.print();
}

int main()
{

    Pirate p;
    Pirate b("Roger");
    Pirate c("Billy");
    Pirate d("Gold Tooth");
    Pirate a("Sam");
     
    ArrayList arr;
    arr.insert_pirate(p);
    arr.insert_pirate(b);
    arr.insert_pirate(c);
    arr.insert_pirate(d);
    arr.insert_pirate(a);

    More_Pirates(arr);

    Pirate * pirates = new Pirate[5];

    pirates[0] = Pirate("Luke?");
    pirates[0].assign_pirate_id();    
    pirates[0].print();

    pirates[1].print()

    return 0;
}

/*
 * ifstream infile;
 * infile.open("pirates.txt")
 * if(!infile.is_open()){
 *     while(!infile.eof()){
 *         cerr << "help";
 *     }
 * }
 */
