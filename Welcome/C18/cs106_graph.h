#ifndef CS106_GRAPH_H
#define CS106_GRAPH_H
#include <string>
#include "set.h"
#include "map.h"
#include "queue.h"
#include <iostream>
using namespace std;



template <typename NodeType, typename ArcType>
class Cs106_graph
{
public:
    Cs106_graph();

    ~Cs106_graph();

    int size() const;

    bool isEmpty() const;

    /* Method: clear
     * Usage: g.clear()
     * Reinitializes the graph to be empth, freeing any heap storage.
     */
    void clear();

    NodeType *addNode(std::string name);
    NodeType *addNode(NodeType *node);


    void removeNode(std::string name);
    void removeNode(NodeType *node);

    /*
     * Method: getNode
     * Usage: NodeTYpe * node = g.getNode(name);
     * Looks up a node in the name table attached to the graph and
     * returns a pointer to that node. If no node with the specified
     * name esists, getNode returns NULL.
     */
    NodeType *getNode(std::string name) const;

    ArcType  *addArc(std::string s1, std::string s2);
    ArcType  *addArc(NodeType *n1, NodeType *n2);
    ArcType  *addArc(ArcType *arc);

    void removeArc(std::string s1, std::string s2);
    void removeArc(NodeType *n1, NodeType *n2);
    void removeArc(ArcType *arc);

    bool isConnected(std::string s1, std::string s2) const;
    bool isConnected(NodeType *n1, NodeType *n2) const;

    Set<NodeType *> & getNodeSet();
    Set<ArcType *> & getArcSet();
    Set<ArcType *> & getArcSet(NodeType *node);
    Set<ArcType *> & getArcSet(std::string name);


    Set<NodeType *> & getNeighbors(NodeType *node);
    Set<NodeType *> & getNeighbors(std::string node);

    /*
     * Function: depth First Search
     * Usage: deepthFirstSearch(node);
    */
    void depthFirstSearch(NodeType *node);
    void visitUsingDFS(NodeType *node, Set<NodeType *> & visited);
    void visit(NodeType *node);

    void breadthFirstSearch(NodeType *node);



    /*
     * Methods: copy constructor and assignment operator
     * These methods implement deep copying for graphs.
     */
    Cs106_graph(const Cs106_graph & src);
    const Cs106_graph & operator=(const Cs106_graph & src);


private:
    Set<NodeType *> nodes;
    Set<ArcType *> arcs;
    Map<std::string,NodeType *> nodeMap;


    void deepCopy(const Cs106_graph & src);
    NodeType *getExistingNode(std::string name) const;
};

#endif // CS106_GRAPH_H

template <typename NodeType, typename ArcType>
Cs106_graph<NodeType,ArcType>::Cs106_graph()
{
    /* Empty */
}

template <typename NodeType, typename ArcType>
Cs106_graph<NodeType,ArcType>::~Cs106_graph()
{
    clear();
}

template <typename NodeType, typename ArcType>
int Cs106_graph<NodeType,ArcType>::size() const{
    return nodes.size();
}

template <typename NodeType, typename ArcType>
bool Cs106_graph<NodeType,ArcType>::isEmpty() const{
    return nodes.isEmpty();
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::clear(){
    for (NodeType *node:nodes){
        delete node;
    }
    for(ArcType * arc:arcs){
        delete arc;
    }
    arcs.clear();
    nodes.clear();
    nodeMap.clear();
}

template <typename NodeType, typename ArcType>
NodeType *Cs106_graph<NodeType,ArcType>::addNode(std::string name){
    if(nodeMap.containsKey(name)){
        error("addName: Node " + name + " already exists");
    }
    NodeType *node = new NodeType();
    node->name = name;
    return addNode(node);
}

template <typename NodeType, typename ArcType>
NodeType *Cs106_graph<NodeType,ArcType>::addNode(NodeType *node){
    nodes.add(node);
    nodeMap[node->name] = node;
    return node;
}

/*
 * Implateation notes: removeNode
 * The removeNode method must remove the specified node but must
 * also remove any arcs in the graph containin the node. To avoid
 * changing the node set during iteration, this implementation creates
 * a vector of arcs that require deletion.
*/
template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::removeNode(std::string name){
    removeNode(getExistingNode(name));
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::removeNode(NodeType *node){
    Vector<ArcType *> toRemove;
    for(ArcType *arc:arcs){
        if (arc->start == node || arc->finish == node){
            toRemove.add(arc);
        }
    }
    for (ArcType *arc: toRemove){
        removeArc(arc);
    }
    nodes.remove(node);
}

/*
 * Implementation notes: getNode, getExistingNode
 * Look up node.
*/

template <typename NodeType, typename ArcType>
NodeType *Cs106_graph<NodeType,ArcType>::getNode(std::string name) const{
    return nodeMap.get(name);
}

template <typename NodeType, typename ArcType>
NodeType *Cs106_graph<NodeType,ArcType>::getExistingNode(std::string name) const{
    NodeType *node = nodeMap.get(name);
    if(node == NULL) error("No node named " + name);
    return node;
}




/*
 * Implateation notes: add Arc
 * The addArc method appears in three forms, as described in the interface.
*/


template <typename NodeType, typename ArcType>
ArcType *Cs106_graph<NodeType,ArcType>::addArc(std::string s1, std::string s2){
    return addArc(getExistingNode(s1), getExistingNode(s2));
}

template <typename NodeType, typename ArcType>
ArcType *Cs106_graph<NodeType,ArcType>::addArc(NodeType *n1, NodeType *n2){
    ArcType *arc = new ArcType();
    arc->start = n1;
    arc->finish = n2;
    return addArc(arc);
}

template <typename NodeType, typename ArcType>
ArcType *Cs106_graph<NodeType,ArcType>::addArc(ArcType *arc){
    arc->start->arcs.add(arc);
    arcs.add(arc);
    return arc;
}

/*
 * Implateation notes: removeArc
 *
*/

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::removeArc(std::string s1, std::string s2){
    removeArc(getExistingNode(s1), getExistingNode(s2));
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::removeArc(NodeType *n1, NodeType *n2){
    Vector<ArcType *>toRemove;
    for(ArcType *arc: arcs){
        if(arc->start == n1 && arc->finish == n2){
            toRemove.add(arc);
        }
    }
    for(ArcType * arc: toRemove){
        removeArc(arc);
    }
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::removeArc(ArcType *arc){
    arc->start->arcs.remove(arc);
    arcs.remove(arc);

}

/*
 * Implateation notes: isConnect
 * Node n1 is connected to n2 if any of the arcs leaving n1 finish n2. *
*/

template <typename NodeType, typename ArcType>
bool Cs106_graph<NodeType,ArcType>::isConnected(std::string s1, std::string s2) const{
    return isConnected(getExistingNode(s1), getExistingNode(s2));
}

template <typename NodeType, typename ArcType>
bool Cs106_graph<NodeType,ArcType>::isConnected(NodeType *n1, NodeType *n2) const{
    for(ArcType *arc: arcs){
        if(arc->finish == n2) return true;
    }
    return false;
}

/*
 * Implateation notes: getNodeSet, get ArcSet
 * These methods simply return the set requested by the client. The
 * sets are returned by reference for efficiency, because doing so
 * eliminates the need to copy the set.
*/

template <typename NodeType, typename ArcType>
Set<NodeType *> & Cs106_graph<NodeType,ArcType>::getNodeSet(){
    return nodes;
}

template <typename NodeType, typename ArcType>
Set<ArcType *> & Cs106_graph<NodeType,ArcType>::getArcSet(){
    return arcs;
}

template <typename NodeType, typename ArcType>
Set<ArcType *> & Cs106_graph<NodeType,ArcType>::getArcSet(NodeType *node){
    return node->arcs;
}

template <typename NodeType, typename ArcType>
Set<ArcType *> & Cs106_graph<NodeType,ArcType>::getArcSet(std::string name){
    return getArcSet(getExistingNode(name));
}

template <typename NodeType, typename ArcType>
Set<NodeType *> & Cs106_graph<NodeType,ArcType>::getNeighbors(NodeType *node){
    Set<NodeType *> nodesResult;
    for(ArcType *arc : node->arcs){
        nodesResult.add(arc->finish);
    }
    return nodesResult;
}

//There are bugsssssss here !!!!!!!!!!!!!! fuck!!!!!!!!!
template <typename NodeType, typename ArcType>
Set<NodeType *> & Cs106_graph<NodeType,ArcType>::getNeighbors(std::string node){

    Set<NodeType *> nodesResult;
    nodesResult = getNeighbors(getExistingNode(node));
    //return getNeighbors(getExistingNode(node));
    return nodesResult;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * These methods ensure that copying a graph creates an entriely new
 * parallel structure of nodes and arcs.
 *
*/
template <typename NodeType, typename ArcType>
const Cs106_graph<NodeType,ArcType> &
        Cs106_graph<NodeType,ArcType>::operator =(const Cs106_graph & src){
    if(this != & src){
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::deepCopy(const Cs106_graph & other){
    for(NodeType *oldNode: other.nodes){
        NodeType * newNode = new NodeType();
        *newNode = *oldNode;
        newNode->arcs.clear();
        addNode(newNode);
    }
    for(ArcType *oldArc : other.arcs){
        ArcType *newArc = new ArcType();
        *newArc = * oldArc;
        newArc->start = getExistingNode(oldArc->start->name);
        newArc->finish = getExistingNode(oldArc->finish->name);
        addArc(newArc);
    }
}








/*
 * Implementation notes: Using DFS to search whole graph
*/

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::depthFirstSearch(NodeType *node){
    Set<NodeType *> visited;
    visitUsingDFS(node, visited);
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::visitUsingDFS(NodeType *node, Set<NodeType *> & visited){
    if(visited.contains(node)) return;
    visit(node);
    visited.add(node);
    for(ArcType *arc: node->arcs){
        visitUsingDFS(arc->finish, visited);
    }
}

template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::visit(NodeType *node){
    cout << node->name << " ";
}



template <typename NodeType, typename ArcType>
void Cs106_graph<NodeType,ArcType>::breadthFirstSearch(NodeType *node){
    Set<NodeType *> visited;
    Queue<NodeType *> queue;
    queue.enqueue(node);
    while(!queue.isEmpty()){
        node = queue.dequeue();
        if(!visited.contains(node)){
            visit(node);
            visited.add(node);
            for(ArcType *arc : node->arcs){
                queue.enqueue(arc->finish);
            }
        }
    }
}

