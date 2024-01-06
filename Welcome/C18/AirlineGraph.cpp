#include <iostream>
#include <string>
#include "graphtypes.h"
#include "set.h"
#include "queue.h"

using namespace std;

void printAdjacencyLists(SimpleGraph &g);
void initAirlineGraph(SimpleGraph & airline);
void addFlight(SimpleGraph & airline, string c1, string c2, int miles);
void addNode(SimpleGraph & g, string name);
void addArc(SimpleGraph & g, Node * n1, Node * n2, double cost);

void depthFirstSearch(Node *node);
void visitUsingDFS(Node *node, Set<Node *> & visited);
void visit(Node *node);
void breadthFirstSearch(Node *node);

int main_ArilineGraph(){
    SimpleGraph airline;
    initAirlineGraph(airline);
    printAdjacencyLists(airline);

    cout << "Use DFS to search" << endl;
    depthFirstSearch(airline.nodeMap["San Francisco"]);;
    cout << "Use BFS to search" << endl;
    breadthFirstSearch(airline.nodeMap["San Francisco"]);
    return -1;
}

void printAdjacencyLists(SimpleGraph &g){
    for(Node *node:g.nodes){
        cout << node->name << " -> ";
        bool first = true;
        for(Arc *arc:node->arcs){
            if(!first) cout << ", ";
            cout << arc->finish->name;
            first = false;
        }
        cout << endl;
    }
}


void initAirlineGraph(SimpleGraph & airline){
    addNode(airline,"Atlanta");
    addNode(airline,"Boston");
    addNode(airline,"Chicago");
    addNode(airline,"Dallas");
    addNode(airline,"Denver");
    addNode(airline,"Los Angeles");
    addNode(airline,"New York");
    addNode(airline,"Portland");
    addNode(airline,"San Francisco");
    addNode(airline,"Seattle");

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

}

void addFlight(SimpleGraph & airline, string c1, string c2, int miles){
    Node * n1 = airline.nodeMap[c1];
    Node * n2 = airline.nodeMap[c2];
    addArc(airline,n1,n2,miles);
    addArc(airline,n2,n1,miles);
}

void addNode(SimpleGraph & g, string name){
    Node * node = new Node;
    node->name = name;
    g.nodes.add(node);
    g.nodeMap[name] = node;
}

void addArc(SimpleGraph & g, Node * n1, Node * n2, double cost){
    Arc * arc = new Arc;
    arc->strat = n1;
    arc->finish = n2;
    arc->cost = cost;
    g.arcs.add(arc);
    n1->arcs.add(arc);
}

void depthFirstSearch(Node *node){
    Set<Node *> visited;
    visitUsingDFS(node, visited);
}

void visitUsingDFS(Node *node, Set<Node *> & visited){
    if(visited.contains(node)) return;
    visit(node);
    visited.add(node);
    for(Arc *arc: node->arcs){
        visitUsingDFS(arc->finish, visited);
    }
}

void visit(Node *node){
    cout << node->name << " ";
}

void breadthFirstSearch(Node *node){
    Set<Node *> visited;
    Queue<Node *> queue;
    queue.enqueue(node);
    while(!queue.isEmpty()){
        node = queue.dequeue();
        if(!visited.contains(node)){
            visit(node);
            visited.add(node);
            for(Arc *arc : node->arcs){
                queue.enqueue(arc->finish);
            }
        }
    }
}













