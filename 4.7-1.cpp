#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;
// Lowest Common Ancester
// If there is no limitation, we know the parent of the node and we can use a map to record each node of the traversing path.

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

struct node* lca(struct node* n1, struct node* n2) {
    if (!n1 || !n2) return NULL;
    map<struct node*, bool> m;
    while (n1) {
        m[n1] = true;
        n1 = n1->parent;
    }
    
    while (n2 && !m[n2]) {
        n2 = n2->parent;
    }
    return n2;
}

int main() {
    struct node* tree = NULL, *n1, *n2, *t;
    tree = insert(tree, 20);
    tree = insert(tree, 8);
    tree = insert(tree, 22);
    tree = insert(tree, 4);
    tree = insert(tree, 12);
    tree = insert(tree, 23);
    tree = insert(tree, 27);
    tree = insert(tree, 70);
    tree = insert(tree, 14);
    n1 = tree->left->left; //4
    n2 = tree->left->right->right; //14
    t=lca(n1, n2);
    cout<<"The common ancester is node: "<<t->data<<endl;
    getchar();
}
//Time complexity of above solution is O(h) where h is height of tree. 
//It requires O(h) extra space in function call stack for recursive function calls.
