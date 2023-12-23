#ifndef BSTREE_H
#define BSTREE_H
#include <string>
using namespace std;


struct BSTNode{
    string key;
    BSTNode *left,*right;
};


class BSTree
{


public:
    BSTNode *head;



    BSTree();
    ~BSTree();

    void insertNode(BSTNode * & t,const string & key);

    BSTNode *findNode(BSTNode *t, const string & key);

    void deleteNode(const string & key);

    /*
     * Method: Tree travels
     * Declare: Post, Mid, Pre display tree.
     */
    void mid_displayTree(BSTNode *t);

    void pre_displayTree(BSTNode *t);

    void post_displayTree(BSTNode *t);

    void displayNode(BSTNode *t);

private:


    BSTNode *cur;
    int count;

};

#endif // BSTREE_H
