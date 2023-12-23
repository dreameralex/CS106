#include "bstree.h"
#include <string>
#include <iostream>
using namespace std;

BSTree::BSTree(){
    cur = head = NULL;
    count = 0;
}

BSTree::~BSTree(){
    cur = head = NULL;
    count = 0;
}



void BSTree::insertNode(BSTNode * & t,const string & key) {
    if (t == NULL) {
        if (count != 0){
            t = new BSTNode;
            t->key = key;
            t->left = t->right = NULL;
            }else{
                t = new BSTNode;
                t->key = key;
                t->left = t->right = NULL;
                head = t;
            }
        count ++;
    } else {
        if (key != t->key) {
            if (key < t->key) {
                insertNode(t->left, key);
            } else {
                insertNode(t->right, key);
            }
        }
    }
}


BSTNode * BSTree:: findNode(BSTNode *t, const string & key) {
    if (t == NULL) {
        return NULL;
    }
    if (key == t->key){
        return t;
    }
    if (key < t->key) {
        return findNode(t->left, key);
    } else {
        return findNode(t->right, key);
    }
}

void BSTree::deleteNode(const string & key) {
    if (count != 0){
        BSTNode *p = head;
        BSTNode *pre = NULL;
        while( p != NULL){
            if(p->key == key){
                break;
            }else if (key < p->key) {
                pre = p;
                p = p->left;
            }else{
                pre = p;
                p = p->right;
            }
        }

        if(p->left == NULL & p->right != NULL){
            cout << 1 << endl;
            if (p == head){
                head = p->right;
                free(p);                
            }
            BSTNode*temp = p;
            (pre->key < p->key ? pre->right:pre->left) = p->right;
            free(temp);
            temp = NULL;
            
            
        }else if(p->right == NULL & p->left != NULL){
            cout << 2 << endl;
            if (p == head){
                head = p->right;
                free(p);                
            }
            BSTNode*temp = p;
            (pre->key < p->key ? pre->right:pre->left) = p->right;
            free(temp);
            temp = NULL;
            
        }
        else{
            cout << 3 << endl;
            BSTNode *post = p;
            BSTNode *max = p->left;
            while(max->right != NULL){
                post = max;
                max = max->right;
            }
            p->key = max->key;
            if(post == p){
                post->left = max->left;
            }else{
                post->right = max->left;
            }
            free(max);
        }

    }
}















/*
 * Method: Tree travels
 * Declare: Post, Mid, Pre display tree.
 */
void BSTree::mid_displayTree(BSTNode *t) {
    if (t != NULL) {
        mid_displayTree(t->left);
        cout << t->key << endl;
        mid_displayTree(t->right);
    }
}

void BSTree::pre_displayTree(BSTNode *t) {
    if (t != NULL) {
        cout << t->key << endl;
        pre_displayTree(t->left);
        pre_displayTree(t->right);
    }
}

void BSTree::post_displayTree(BSTNode *t) {
    if (t != NULL) {
        post_displayTree(t->left);
        post_displayTree(t->right);
        cout << t->key << endl;
    }
}

void BSTree::displayNode(BSTNode *t){
    if(t != NULL){
        cout << t->key << endl;
    }
}

