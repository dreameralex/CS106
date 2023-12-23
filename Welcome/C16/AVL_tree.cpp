#include <string>
#include <iostream>
#include <queue>
using namespace std;

struct BSTNode{
    string key;
    BSTNode *left, *right;
    int bf;
};
void insertNode(BSTNode * & t, string key);
int insertAVL(BSTNode * & t, string key);
void fixLeftImbalance(BSTNode * & t);
void rotateLeft(BSTNode * & t);
void fixRightImbalance(BSTNode * & t);
void rotateRight(BSTNode * & t);
void mid_displayTree(BSTNode *t);
void levelOrderTraversal(BSTNode* root);


int main_test_avltree(){
    BSTNode *tree = NULL;
    insertAVL(tree, "a");
    insertAVL(tree, "b");
    insertAVL(tree, "c");
    insertAVL(tree, "d");
    //insertAVL(tree, "e");

    mid_displayTree(tree);
    levelOrderTraversal(tree);

    return -1;
}

void insertNode(BSTNode * & t, string key){
    insertAVL(t,key);
}

int insertAVL(BSTNode * & t, string key){
    if ( t == NULL ){
        t = new BSTNode;
        t->key = key;
        t->bf = 0;
        t->left = t->right = NULL;
        return +1;
    }
    if(key == t->key) return 0;
    if(key < t->key){
        int delta = insertAVL(t->left,key);
        if (delta == 0) return 0;
        switch (t->bf){
        case +1: t->bf =  0;return  0;
        case  0: t->bf = -1;return +1;
        case -1: fixLeftImbalance(t);return 0;
        }
        return 0;
    }else{
        int delta = insertAVL(t->right, key);
        if(delta==0) return 0;
        switch (t->bf){
        case -1: t->bf=0;return 0;
        case 0: t->bf=+1;return +1;
        case +1: fixRightImbalance(t);return 0;
        }
    }
    return 9999;
}

void fixLeftImbalance(BSTNode * & t){
    cout << "fixLeftImbalance" << endl;
    BSTNode *child = t->left;
    if(child->bf != t->bf){
        int oldBF = child->right->bf;
        rotateLeft(t->left);
        rotateRight(t);
        t->bf = 0;
        switch (oldBF) {
        case -1: t->left->bf = 0; t->right->bf = +1; break;
        case  0: t->left->bf = t->right->bf = 0; break;
        case +1: t->left->bf = -1; t->right->bf = 0; break;
        }
    }else{
        rotateRight(t);
        t->right->bf = t->bf = 0;
    }
}



void rotateLeft(BSTNode * & t){
    BSTNode *child = t->right;
    t->right = child->left;
    child->left = t;
    t = child;
}

void fixRightImbalance(BSTNode * & t){
    cout << "fixRightImbalance" << endl;
    BSTNode *child = t->right;
    if(child->bf != t->bf){
        int oldBF = child->left->bf;
        rotateRight(t->right);
        rotateLeft(t);
        t->bf = 0;
        switch (oldBF) {
        case -1: t->left->bf = 0; t->right->bf = +1; break;
        case  0: t->left->bf = t->right->bf = 0; break;
        case +1: t->left->bf = -1; t->right->bf = 0; break;
        }
    }else{
        rotateLeft(t);
        t->left->bf = t->bf = 0;
    }
}

void rotateRight(BSTNode * & t){

    BSTNode *child = t->left;
    t->left = child->right;
    child->right = t;
    t = child;
}

void mid_displayTree(BSTNode *t) {
    if (t != NULL) {
        mid_displayTree(t->left);
        cout << t->key << endl;
        mid_displayTree(t->right);
    }
}


void levelOrderTraversal(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    queue<BSTNode*> q;
    q.push(root);
    while (!q.empty()) {
        BSTNode* node = q.front();
        q.pop();
        cout << node->key << " ";
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}


