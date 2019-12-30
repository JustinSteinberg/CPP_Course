//MetroSim.cpp
//Author: Justin Steinberg
//Comp15 HW3
//Date: Feb 21st, 2019
//Implementation of the Metro Simulator
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "MetroSim.h"

using namespace std;

/*Constructor*/
MetroSim::MetroSim(){
    
    flag = 0;
    flag2 = 0;
    forward = true;
    numPassengers = 0;
    size = 1;               //Size of Station vector
    currPos = 1;            //Position of Train
    vector <Passenger> Train;
    vector <Station> Stations;
    vector <int> LeftTrainId;
    vector <int> LeftTrainDestin;

}

//Input: A Passenger Object
//Returns: Nothing
//Does: Adds a Passenger to Stations vector
void MetroSim::AddToStation(Passenger P){

    numPassengers++;    
    P.id = numPassengers;
   
    for(unsigned int i = 1; i < Stations.size(); i++){
        if(P.arrival == Stations.at(i).num){
            Stations.at(i).myVector.push_back(P);
        }
    }    
    printTrain();
               
}

//Input: Nothing
//Returns: Nothing
//Does: Adds passengers at the station to the train and removes 
//      the passengers from the station.
//     Also checks if the train should move forwards of backwards
void MetroSim::AddToTrain(){

     unsigned int length = Stations.at(currPos).myVector.size();

     for(unsigned int i = 0; i<length; i++){
         Train.push_back(Stations[currPos].myVector[i]);
     }
     
     Stations.at(currPos).myVector.clear();

     if(forward == true){
         currPos++;
         if(currPos == Stations.size()-1){
              forward = false;
         }
     }
     else if(forward == false){
          currPos--;
          if(currPos == 1){
              forward = true;
          }
     }
}

//Input: File Name, Int of two Flags
//Flag2 determines when we should print to the terminal
//Returns: Nothing
//Does: Removes the passengers from the train when they
//      arrive at their destination. Also calls printTrain().
//      This function also calls the PrintToPassFile
//      function, which is why we have inputs for this function.
void MetroSim::RemoveFromTrain(string file, int flag, int flag2){

    if(Train.size() >= 1){

        for(unsigned int i = Train.size(); i > 0; i--){
            if(Train[i].destin == Stations[currPos].num){ 
                PrintToPassFile(file, Train[i].id, Train[i].destin, flag);
                Train.erase(Train.begin()+(i));
            }
        }

        PrintToPassFile(file,Train[0].id,Train[0].destin,flag); 
        Train.erase(Train.begin());
    }

    if(flag2 == 0){
        printTrain();
    }
}

//Input: File name from where you get station names
//Returns: Nothing
//Does: Reads Stations from file and puts them in a vector
void MetroSim::ReadInStations(string file){
    string STATIONS_FILE = file;

     // Read in original list from file
    ifstream infile;
    infile.open(STATIONS_FILE.c_str());
    if (!infile.is_open()){
        cerr << "Could not add station from file\n";
        return;
    }
    
 
    string stationName = "";
    Station null;

    Stations.push_back(null);

    while(getline(infile, stationName)){
        Station s;
        s.name = stationName;
        s.num = size;
        Stations.push_back(s);
        size++;
    }
  
    infile.close();
}

//Input: String file, Int Id, Int destination, int flag
//Returns: Nothing
//Does: Prints the passengers to the pass file in the 
//      specified format defined in the homework
void MetroSim::PrintToPassFile(string file, int id, int destin, int flag){

    LeftTrainId.push_back(id);
    LeftTrainDestin.push_back(destin);   

    if(flag == 1 && LeftTrainId.size() > 0){
        ofstream outfile;
        outfile.open(file.c_str());
        flag = 2;
        if (!outfile.is_open()){
            cerr << "Error: could not open file " << file << "\n";
            return;
        }
    
        for(unsigned int i = LeftTrainId.size()-2; i > 0; i--){
            outfile << "Passenger " << LeftTrainId[i] << " left train at station ";
            for(unsigned int j = i; j >= i; j--){
                outfile << LeftTrainDestin[j] << endl;
            }
        }
        outfile << "Passenger " << LeftTrainId[0] << " left train at station ";
        outfile << LeftTrainDestin[0] << endl;

        outfile.close();
    }
}

//Input: Nothing
//Returns: Nothing
//Does: Prints the Train Vector to the terminal in the manner
//      defined in the homework
void MetroSim::printTrain(){

     cout << "Passengers on the train: ";

     if(Train.size() > 0){
         for(unsigned int i = 0; i<Train.size(); i++){
             cout << "{[" << Train[i].id;
             cout << ", " << Train[i].arrival << "->" << Train[i].destin << "]} ";
         }
         cout << endl;
     }   
     else{
         cout << "{}" << endl;
     }

     printStations();

}

//Input: Nothing
//Returns: Nothing 
//Does: Prints the Stations vector as well as where the train
//      is relative to the stations to the terminal in 
//      appropriate fashion
void MetroSim::printStations(){

    for(unsigned int i = 1; i<Stations.size(); i++){
        if(currPos == i){
           cout << "TRAIN: " << "["<<i<<"] " << Stations[i].name;
        }
        else{
           cout << "       ["<<i<<"] " << Stations[i].name;
        }
        if(Stations.at(i).myVector.size() == 0){
            cout << " {}" << endl;
        }
        else{
            for(unsigned int j = 0; j<Stations.at(i).myVector.size(); j++){
                cout << " {[" << Stations.at(i).myVector[j].id <<", "<< Stations.at(i).myVector[j].arrival <<"->"<< Stations.at(i).myVector[j].destin << "]";
            }
            cout << "}" << endl; 
        }

    }
}

//THIS VERSION OF PRINT STATIONS IS FOR MY UNIT TEST//
//JUST COPIED AND PASTED THE ABOVE FUNCTION AND CHANGED
//THE NAME SO I CAN MAKE IT A PUBLIC FUNCTION  
void MetroSim::printStation(){

    for(unsigned int i = 1; i<Stations.size(); i++){
        if(currPos == i){
           cout << "TRAIN: " << "["<<i<<"] " << Stations[i].name;
        }
	else{
           cout << "	   ["<<i<<"] " << Stations[i].name;
        }
	if(Stations.at(i).myVector.size() == 0){
            cout << " {}" << endl;
        }
	else{
            for(unsigned int j = 0; j<Stations.at(i).myVector.size(); j++){
                cout << " {[" << Stations.at(i).myVector[j].id <<", "<< Stations.at(i).myVector[j].arrival <<"->"<< Stations.at(i).myVector[j].destin << "]";
            }
            cout << "}" << endl;
        }

    }
}


