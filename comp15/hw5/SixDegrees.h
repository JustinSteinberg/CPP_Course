//Author: Justin Steinberg
//Implementation of the SixDegrees class
#include <iostream>
#include <string>
#include "Graph.h"
#include "Actors.h"
using namespace std;

#ifdef SIXDEGREES_H_
#define SIXDEGREES_H_

class SixDegrees
{
public:

    SixDegrees();
    void populate_graph(Graph<string> &g);
    void compare_actors(Actors actors[], int num_actors) 
    void run(istream &in, ostream &out);
    void BFS(Actor a, Actor b, ostream &out);

private:

    Graph<string> g; 

};

#endif
