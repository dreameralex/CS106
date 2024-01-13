#include <iostream>
#include <string>
#include "cs106_graph.h"
using namespace std;


struct NodeType;
struct ArcType;

struct NodeType{
    std::string name;
    Set<ArcType *> arcs;
};

struct ArcType{
    NodeType *start;
    NodeType *finish;
    double cost;
};

void Add_AirLine(Cs106_graph<NodeType,ArcType> & airline, string start,string finish, double cost);

void show_arcs(const Vector<ArcType *> & path);

int main(){
    Cs106_graph<NodeType,ArcType> airline;
    airline.addNode("alex");



    airline.addNode("Atlanta");
    airline.addNode("Boston");
    airline.addNode("Chicago");
    airline.addNode("Dallas");
    airline.addNode("Denver");
    airline.addNode("Los Angeles");
    airline.addNode("New York");
    airline.addNode("Portland");
    airline.addNode("San Francisco");
    airline.addNode("Seattle");

    Set<ArcType *> airline_set = airline.getArcSet();
    Add_AirLine(airline,"Atlanta","Chicago",100.0);

    Add_AirLine(airline,"Atlanta","Chicago",599.0);
    Add_AirLine(airline,"Atlanta","Dallas",725.0);
    Add_AirLine(airline,"Atlanta","New York",871.0);
    Add_AirLine(airline,"Boston","New York",32.0);
    Add_AirLine(airline,"Boston","Seattle",9764544.0);
    Add_AirLine(airline,"Chicago","Denver",123.0);
    Add_AirLine(airline,"Dallas","Denver",1231.0);
    Add_AirLine(airline,"Dallas","Los Angeles",4657.0);
    Add_AirLine(airline,"Dallas","San Francisco",9948.0);
    Add_AirLine(airline,"Portland","San Francisco",987465.0);
    Add_AirLine(airline,"Portland","Seattle",321564.0);
    Add_AirLine(airline,"Atlanta","Chicago",78165154865465.0);


    cout << "Test serach BFS:" << endl;
    NodeType *alex_node = airline.getNode("Atlanta");
    airline.breadthFirstSearch(alex_node);
    cout << endl;

    cout << "Test Dijkstra:" << endl;




    Vector<ArcType *> shortestpath = airline.findShortestPath("Atlanta","San Francisco");

    show_arcs(shortestpath);






    /*
    ArcType *arc;
    arc = airline.get_arc("Atlanta","Chicago");
    cout << arc->cost;

    airline.getPathCost()




    addFlight(airline,"Atlanta","Chicago",599);
    addFlight(airline,"Atlanta","Dallas",725);
    addFlight(airline,"Atlanta","New York",871);
    addFlight(airline,"Boston","New York",32);
    addFlight(airline,"Boston","Seattle",9764544);
    addFlight(airline,"Chicago","Denver",123);
    addFlight(airline,"Dallas","Denver",1231);
    addFlight(airline,"Dallas","Los Angeles",4657);
    addFlight(airline,"Dallas","San Francisco",9948);
    addFlight(airline,"Portland","San Francisco",987465);
    addFlight(airline,"Portland","Seattle",321564);
    addFlight(airline,"Atlanta","Chicago",78165154865465);
    airline



*/


    return 0;
}

void Add_AirLine(Cs106_graph<NodeType,ArcType> & airline, string start,string finish, double cost){
    airline.addArc(start,finish);
    ArcType *arc;
    arc = airline.get_arc(start,finish);
    arc->cost = cost;
}


void show_arcs(const Vector<ArcType *> & path){
    int i = 0;
    double TotalCost = 0;
    for(auto iter:path){

        cout << "Step" << i <<": " << iter->finish->name << "," <<iter->cost  << endl;
        i++;
        TotalCost += iter->cost;
    }
    cout << "Total cost:" << TotalCost;
}
