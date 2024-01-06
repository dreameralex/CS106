#ifndef CS106_GRAPH_H
#define CS106_GRAPH_H
#include <string>
#include "set.h"
#include "map.h"

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

    Set<NodeType *> & getArcSet();
    Set<NodeType *> & getArcSet(NodeType *node);
    Set<NodeType *> & getArcSet(std::string name);


    Set<NodeType *> & getNeighbores(NodeType *node);
    Set<NodeType *> & getNeighbores(std::string name);


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

template <typename NodeType, typename ArcType>
NodeType *Cs106_graph<NodeType,ArcType>::getExistingNode(std::string name) const{
    NodeType *node = nodeMap.get(name);
    if(node == NULL) error("No node named " + name);
    return node;
}

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

template <typename NodeType, typename ArcType>
Set<NodeType *> & Cs106_graph<NodeType,ArcType>::getArcSet(NodeType *node){

    return node.arcs;
}
