using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "bstree.h"

int main_tree(){
    cout << "Test Tree:" << endl;
    BSTree tree;
    BSTNode *p = tree.head;



    //cout << "head: " << tree.head;
    tree.insertNode(p,"c");
    tree.insertNode(p,"a");
    tree.insertNode(p,"b");
    tree.insertNode(p,"d");
    tree.insertNode(p,"e");
    tree.insertNode(p,"f");
    tree.insertNode(p,"g");

    //cout << "P:"<< p << " " << p->key << endl;




    //cout << tree.head->key;

    cout << "Mid display:" << endl;
    tree.mid_displayTree(p);

    /*
    cout << "Pre display:" << endl;
    tree.pre_displayTree(p);

    cout << "Post display:" << endl;
    tree.post_displayTree(p);
    */


    BSTNode *q = new BSTNode;
    q = tree.head;
    /*
    cout << "Find Node:" << endl;
    cout << q->key;
    q = tree.findNode(q, "c");
    tree.displayNode(q);
    */

    cout << "Delete" << endl;
    tree.deleteNode("c");
    tree.mid_displayTree(tree.head);


    return 1;
}
