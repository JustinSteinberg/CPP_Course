//MetroSim.h
//Author: Justin Steinberg
//Spring 2019
//Assignment: Comp15 HW3
//Interface for the Metro Simulator Assignment
///////////////////

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#ifndef _METROSIM_H_
#define _METROSIM_H_

//optional
struct Passenger
{

int id;                   //Id to keep track of passenger
int arrival;              //Arrival station of passenger
int destin;               //Destination of passenger

};

//optional
struct Station
{
int num;                    //Numbers of Station
string name;                //Name of Station
vector<Passenger> myVector; //Vector of Passengers at the station
};


class MetroSim{
	public:
                MetroSim();                    //Default Constructor
                void AddToStation(Passenger);  //Adds passenger to stations
                void AddToTrain();             //Adds passengers to train
               
                void printStation();  //For Unit Test//

                void RemoveFromTrain(string, int=0, int=0); //Removes passengers
                void ReadInStations(string);                //Creates stations
                void PrintToPassFile(string, int, int, int=0); //Out stream 
	private:                                               //to pass file
               
                void printTrain();        //prints train to terminal      
                void printStations();     //prints stations to terminal  
                bool forward;             //Determines if the train goes forward 
   
                int numPassengers;        //Number of total passengers

                unsigned int currPos;     //Position of train

                int size;                 //Size of Stations vector

                int flag;                 //These two flags allow me to determine
                int flag2;                //When I want to stop printing to the 
                                          //terminal and print to the Pass File

                vector <Passenger> Train; //Vector of train passengers

                vector <Station> Stations;//Vector of Stations 

                vector <int> LeftTrainId;     //Vector of ids of passengers that
                vector <int> LeftTrainDestin; //left the train and vector of
                                              //the destination of passangers 
                                              //that left the train   
};                                            //It is used to help print to the
                                              //pass file
#endif
