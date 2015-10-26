#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/
using namespace std;
// Search the larger tree T1, each time a node in T1 matches the root, then compare two subtrees to see if they are identical.

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
    return (node);
}

bool matchTree(struct node* n1, struct node* n2) {
    if (!n1 && !n2) return true; // base case
    
    // if either of them is empty
    if (!n1 || !n2) return false;
    
    if (n1->data != n2->data) return false; // data doesn't match
    return (matchTree(n1->left, n2->left) && matchTree(n1->right, n2->right));
}

bool subTree(struct node* n1, struct node* n2) {
    if (!n1) return  false; // Big tree empty && subtree still not found.
    if (n1->data == n2->data) {
        if (matchTree(n1, n2)) return true;
    }
    return (subTree(n1->left, n2) || subTree(n1->right, n2));
}

bool containsTree(struct node* t1, struct node* t2) {
    if (!t2) return true; // The empty tree is always a subtree
    return subTree(t1, t2);
}


int main() {
    struct node* t1 = newNode(9);
    t1->left = newNode(7);
    t1->right = newNode(11);
    t1->left->left = newNode(5);
    t1->left->right = newNode(8);
    t1->left->left->left = newNode(1);
    t1->left->left->right = newNode(6);
    t1->right->left = newNode(10);
    t1->right->right = newNode(12);
    
    struct node* t2 = newNode(5);
    t2->left = newNode(1);
    t2->right = newNode(6);
    int c = containsTree(t1, t2);
    cout<<"T2 is a subtree of T1? (Y/N, 1/0): "<< c <<endl;
    getchar();
}

// Runtime is around O(n+km), n is the number of nodes in T1 and m is the number of nodes in T2,
// k is the number of occurrences of T2's root in T1. We call k times of treeMatch.
