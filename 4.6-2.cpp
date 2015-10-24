#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;
// Search from root, parent pointer is not needed. 2 cases:
// 1) If right subtree of node exists, then next node lies in right subtree. So go to right subtree and return the node with minimum value in right subtree
// 2) Right subtree doesn't exist, then start from root. Go down, if node's value is bigger than root's value then go right side, otherwise go left side.
struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

// helper function that generates a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return (node);
}

struct node* minNode(struct node* node);

struct node* inOrderSuccessor(struct node* root, struct node* n) {
    // if it has right subtree
    if (n->right != NULL) return minNode(n->right);
    
    // if it has no right subtree, search down from root.
    struct node* next=NULL;
    while (root) {
        if (root->data > n->data) {
            next = root;
            root = root->left;
        }
        
        else root = root->right;
    }
    return next;
}

// find minimum in the tree, because of the BST, no need to search the entire tree
struct node* minNode(struct node* node) {
    struct node* cur = node;
    
    // search the leftmost leaf
    while (cur->left) {
        cur = cur->left;
    }
    return  cur;
}

// for testing, given a BST, inserts a new node, return the new node's parent for the purpose of this quesiton (given a node which is linked to its parent)
struct node* insert(struct node* node, int data) {
    // if the tree is empty return a new node
    if (!node) return(newNode(data));
    else {
        struct node* tmp;
        
        // recur down the tree
        if (data <= node->data) {
            tmp = insert(node->left, data);
            node->left = tmp;
            tmp->parent = node;
        }
        else {
            tmp = insert(node->right, data);
            node->right = tmp;
            tmp->parent = node;
        }
        // return the node pointer
        return node;
    }
}


int main() {
    struct node* tree = NULL, *cur, *next;
    tree = insert(tree, 20);
    tree = insert(tree, 8);
    tree = insert(tree, 22);
    tree = insert(tree, 4);
    tree = insert(tree, 12);
    tree = insert(tree, 10);
    tree = insert(tree, 14);
    cur = tree->left->right->left;
    next = inOrderSuccessor(tree, cur);
    cout<<"The next node of node "<<cur->data<<" is "<<next->data<<endl;
    getchar();
}

