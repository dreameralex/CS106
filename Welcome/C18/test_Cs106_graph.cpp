#include <iostream>
#include <string>
#include "cs106_graph.h"
#include "graph.h"
#include "queue.h"
#include "vector.h"
#include "priorityqueue.h"

using namespace std;

struct NodeType;
struct ArcType;

double getPathCost(const Vector<ArcType *> & path);
Vector<ArcType *> findShortestPath(NodeType *start, NodeType *finish);
void show_arcs(const Vector<ArcType *> & path);

struct NodeType{
    std::string name;
    Set<ArcType *> arcs;
};

struct ArcType{
    NodeType *start;
    NodeType *finish;
    double cost;
};

int main_testgraph(){
    cout << "test";



    Cs106_graph<NodeType,ArcType> g1;

    cout<< "test isEmpty" << endl;
    if (g1.isEmpty()){
        cout << "Is Empty" << endl;
    }else{
        cout << "Not Empty" << endl;
    }

    cout<< "test Size" << endl;
    cout << g1.size() << endl;
    cout << endl;

    cout << "Add Node" << endl;
    g1.addNode("alex");
    g1.addNode("tom");
    g1.addNode("gavin");
    cout << g1.size() << endl;
    g1.removeNode("gavin");
    cout << g1.size() << endl;
    cout << endl;


    cout << "Add arc" << endl;
    g1.addArc("alex","tom");
    g1.removeArc("alex","tom");
    g1.addArc("alex","tom");

    g1.addNode("gavin1");
    g1.addArc("gavin1","tom");
    g1.addNode("mark");
    g1.addArc("mark","tom");

    g1.addArc("tom","mark");
    g1.addArc("tom","alex");
    cout << endl;

    cout << "Test get Node" << endl;
    Set<NodeType *> test_node;
    test_node = g1.getNodeSet();
    cout << test_node.size();
    Set<ArcType *> test_arcs;
    test_arcs = g1.getArcSet();
    cout << endl;

    cout << "Test get neighbors" << endl;
    Set<NodeType *> test_neighbors_node;


    cout << "test ";
    cout << "There are bugs in getNeighbors" << endl;
    //cout << g1.getNeighbors("tom")    ;

    cout << "Test Copy" << endl;
    Cs106_graph<NodeType,ArcType> g2;
    g2=g1;
    cout << "copy graph size is : "<< g2.size();

    cout << "Test serach BFS:" << endl;
    NodeType *alex_node = g1.getNode("alex");
    g1.breadthFirstSearch(alex_node);
    cout << endl;

    cout << "Test serach BFS:" << endl;
    g1.depthFirstSearch(alex_node);
    cout << endl;

    cout << "Test findShortestPath:" << endl;
    NodeType *tom_node = g1.getNode("tom");
    Vector<ArcType *> shortestpath = findShortestPath(tom_node,alex_node);

    shortestpath = g1.findShortestPath(tom_node,alex_node);





    show_arcs(shortestpath);






    return 1;
}

/*
Vector<ArcType *> findShortestPath(NodeType *start, NodeType *finish){
    Vector<ArcType *> path;
    PriorityQueue< Vecotr<ArcType *> > queue;

}
*/

Vector<ArcType *> findShortestPath(NodeType *start, NodeType *finish){
    Vector<ArcType *> path;
    PriorityQueue<Vector<ArcType *> > queue;
    Map<string,double> fixed;
    while(start!=finish){
        if(!fixed.containsKey(start->name)){
            fixed.put(start->name, getPathCost(path));
            for(ArcType *arc:start->arcs){
                if(!fixed.containsKey(arc->finish->name)){
                    path.add(arc);
                    double cost = getPathCost(path);
                    queue.enqueue(path,cost);
                    path.remove(path.size()-1);
                }
            }
        }
        if(queue.isEmpty()){
            path.clear();
            return path;
        }
        path = queue.dequeue();
        start = path[path.size() -1]->finish;
    }
    return path;
}

double getPathCost(const Vector<ArcType *> & path){
    double cost = 0;
    for(ArcType *arc : path){
        cost += arc->cost;
    }
    return cost;
}



