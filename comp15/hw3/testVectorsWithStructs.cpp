//testVectorsWithStructs.cpp
//Author: Justin Steinberg
//Comp15 HW3
//Spring 2019
//This file is a UNIT TEST to make sure 
//that I was able to read in the stations 
//from the command line properly as well 
//as make sure I could add Passangers to the station 
//and then print the stations to the terminal.
//This was when I was first getting used to using
//vectors and structs together.


#include <iostream>
#include <fstream>
#include <string>
#include "MetroSim.h"

using namespace std;

int main(int argc, char* argv[]){

        string arg1(argv[1]);

        MetroSim sim;

        Passenger P;
        P.arrival = 1;
        P.destin = 2;

        Passenger PP;
        PP.arrival = 2;
        PP.destin = 5;

        sim.ReadInStations(arg1);
        sim.AddToStation(P);
        sim.AddToStation(PP);
        sim.printStation();   //This was when I still was using printStations
                               //as a private function but I can assure you it
        return 0;              //worked
}


