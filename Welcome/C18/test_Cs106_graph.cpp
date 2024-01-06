#include <iostream>
#include <string>
#include "cs106_graph.h"
#include "graph.h"

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

int main(){
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
    cout << g1.size() << endl;
    cout << endl;


    cout << "Add arc" << endl;
    g1.addArc("alex","tom");
    cout << endl;




    return 1;
}

