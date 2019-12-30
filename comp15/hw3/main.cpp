//main.cpp
//Author: Justin Steinberg
//Comp15 HW #3
//Feb 21st, 2019
//This file is the driver for the Metro Simulator
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include "MetroSim.h"

using namespace std;

int main(int argc, char* argv[]){

    string arg1;
    string arg2;

    if(argc == 3){        //Check if we have all our inputs//
        arg1 = argv[1];
        arg2 = argv[2];
     }
     
     else if(argc == 2){
        arg1 =argv[1];
     }

        MetroSim sim;    //Create our MetroSim object//

        sim.ReadInStations(arg1); //Read Stations from File//
        bool move = true;
        sim.RemoveFromTrain(arg2);  //Create the stations & Print//        

        while(move == true){    //While the simulation is running//
            cout << "Command: ";
            string str, str1, str2, str3;
            getline(cin, str);
            istringstream iss(str);
            iss >> str1 >> str2 >> str3;

        ///////////////////////////////////////////////////////
        //Here we check all of our commands from the terminal//
        ///////////////////////////////////////////////////////

            if( str1 == "mm" || (str1 == "m" && str2 == "m")){
                sim.AddToTrain();   
                sim.RemoveFromTrain(arg2);
            }

            else if(str1 == "p" || str1 == "P"){
                Passenger P;
                int num1, num2;
                istringstream(str2) >> num1; //Convert string to int
                istringstream(str3) >> num2;
                P.arrival = num1;
                P.destin = num2;
                sim.AddToStation(P);
            } 
            else if(str1 == "f"){
                arg2 = str2;
                sim.RemoveFromTrain(arg2);   
            }
            else if(str1 == "mf" || (str1 == "m" && str2 == "f")){
                cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
                sim.PrintToPassFile(arg2, 0, 0, 1);
                move = false;
            }
        }
	return 0;
}
