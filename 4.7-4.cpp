#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// Lowest Common Ancester
// Not necessarily a BST, no map/hashtable
// With links to parents
// Set n2, trace back n1's parent, check if this parent is also parent of n2.

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

// set n2, trace back n1's parent, check if this parent is also parent of n2.
struct node* lca(struct node* n1, struct node* n2) {
    if (!n1 || !n2) return NULL;
    if (n1==n2) return n1;
    while (n1) {
        if (n1->left == n2 || n1->right == n2) return n1;
        n1 = n1->parent;
    }
    return NULL;
}

int main() {
    struct node* tree = NULL, *n1, *n2, *t;
    tree = insert(tree, 9);
    tree = insert(tree, 7);
    tree = insert(tree, 11);
    tree = insert(tree, 5);
    tree = insert(tree, 8);
    tree = insert(tree, 10);
    tree = insert(tree, 12);
    tree = insert(tree, 1);
    tree = insert(tree, 6);
    n1 = tree->left->left->left; //1
    n2 = tree->left->right; //8
    t=lca(n1, n2);
    cout<<"The common ancester is node: "<<t->data<<endl;
    getchar();
}

