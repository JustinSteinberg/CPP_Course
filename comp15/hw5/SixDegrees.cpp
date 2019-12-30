//Author: Justin Steinberg
//SixDegrees Class source code
//THIS CODE IS VERY UNFINISHED UNFORTUNATELY I HAD NO TIME
//THIS WEEK BECAUSE I HAD TWO EXAMS HOPEFULLY I CAN SHOW
//I UNDERSTAND THE CONCEPTS, I HAVE NO MORE TOKENS,
//I TRIED MY BEST WITH THE TIME I HAD. THANK YOU

/*
#include "SixDegrees.h"
#include "Graph.h"
#include "Actors.h"
#include<iostream>
using namespace std;

//Constructor
SixDegrees::SixDegrees(int num_v){

    cout << "SixDegrees Initialized" << endl;

}

//Input: A reference to a graph object
//Output: Nothing
//Does: Gets data from file, initializes the graph, and populates the
//verticies and edges.
void SixDegrees::populate_graph(Graph<string> &g){

    graph<string> g = g;

    ifstream infile;
    infile.open("actors.txt");
    if (!infile.is_open())
    {
        cerr << "Could not open " << filename << " for reading\n";
        exit(1);
    }
    
    int num_actors = 0;
    string v;
    while(getline(infile,v,'*')){
        num_actors++;    
    }

    g.initalize_graph(num_actors)
    Actors actors[num_actors];    
    int i = 0;
    int j = 0;
    while(!infile.eof()){
        if(i == 0){
            getline(infile, v);
            if(j < num_actors){
                actors[j].insert_name(v);
            }
            g.add_vertex(v);
            i++;
        }
        else{
            getline(infile, v);
            if(v == '*'){
               i = 0;
               j++;
            }
            else{
                actors[j].insert_movie(v);
            }
        }
    }

    infile.close();
    compare_actors(actors, num_actors);

}

void SixDegrees::compare_actors(Actor actors[], int num_actors){

    for(int i = 0; i < num_actors; i++){
        for(int j = i; j < num_actors; j++){
            string s = actors[i].connect(actors[j])
            if(s != ""){
                string name1 = actors[i].get_name();
                string name2 = actors[j].get_name();
                g.add_edge(name1,name2 ,s);
            }
        }      
    }
}

void SixDegrees::run(istream &in, ostream &out){

    out << "Enter two actor names separated by a new line" << endl 
    out << "Press ctrl-D to quit" << endl;
    string actor1;
    string actor2;
    while(getline(in,actor1))
    {
         if(actor1 == "^D"){
             break;
         }
         if(g.is_vertex(actor1)	== false){
             out << "Sorry " << actor1 << " is not in the list" << endl;
         }
   
         while(getline(in,actor2))
         {
             if(actor1 == "^D"){
                 break;
             }

             if(g.is_vertex(actor2) == false){
                 out << "Sorry " << actor2 << " is not in the list" << endl;
             }
             else{
                 break;
             }
         }
        
        //BFS(actor1, actor2, out); (needs to take actors)
    }    
}

void SixDegrees::BFS(Actor a, Actor b, ostream &out){

    g.clear_marks();
    g.initialize_path();

    Queue<string> Queue_one;     //vertices we need to explore
    Queue<string> Queue_two;     //enqueue neighbors of current vertex
    Queue_one.enqueue(a.get_name());

    while(Queue_one.is_empty() == false){
        string curr = "";
        Queue_one.dequeue(curr);
        if(g.is_marked(curr) == false){
            g.mark_vertex(curr);
            g.get_to_vertices(curr, Queue_two);
            while(Queue_two.is_empty() == false){
                string s = "";
                Queue_two.dequeue(s);
                if(s == b.get_name()){
                    g.update_predecessor(curr, s);
                    g.mark_vertex(s);
                    g.report_path(cout, start, end);
                    return;
                }
                else{
                    g.update_predecessor(curr, s);
                    Queue_one.enqueue(s);

                }
           }
	}
    }

}
*/ 
