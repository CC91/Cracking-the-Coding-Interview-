#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;
// Better solution: look at each node only once, write a utility helper function that traverses down the tree, narrow min and max.
// Reference: http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// tree node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// helper function
int isBSTutil(struct node* root, int min, int max);

// return true if the given tree is a BST
int isBST(struct node* root) {
    return(isBSTutil(root, INT_MIN, INT_MAX));
}

// returns true if the given tree is a BST and its values are in [min, max]
int isBSTutil(struct node* root, int min, int max) {
    if (root==NULL) return 1; // base case
    
    if (root->data < min || root->data > max) return 0; // return false if the current node is not in the range
    
    // otherwise check the subtree recursively, narrow the min and max
    return isBSTutil(root->left, min, root->data-1) &&
    isBSTutil(root->right, root->data+1, max);
}

int main() {
    struct node* t = newNode(5); // 9 for bst, #<9 not bst
    t->left = newNode(7);
    t->right = newNode(11);
    t->left->left = newNode(5);
    t->left->right = newNode(8);
    t->left->left->left = newNode(1);
    t->left->left->right = newNode(6);
    t->right->left = newNode(10);
    t->right->right = newNode(12);
    if (isBST(t)) cout<<"It is BST."<<endl;
    else cout<<"It is not BST."<<endl;
}



