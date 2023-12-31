#ifndef GRAPHTYPES_H
#define GRAPHTYPES_H

#include "graphtypes.h"
#include "map.h"
#include "set.h"

struct Node;
struct Arc;

struct SimpleGraph{
    Set<Node *> nodes;
    Set<Arc *> arcs;
    Map<std::string,Node *> nodeMap;
};

struct Node{
    std::string name;
    Set<Arc *> arcs;
};

struct Arc{
    Node *strat;
    Node *finish;
    double cost;
};
#endif // GRAPHTYPES_H
