#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// Lowest Common Ancester
// If it is a BST, then traverse up using parent pointer and print the first intersecting node.

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// helper function that generates a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}


struct node* lca(struct node* root, struct node* n1, struct node* n2) {
    if (!root) return NULL; // base case
    
    // if both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1->data && root->data > n2->data)
        return lca(root->left, n1, n2);
    // if both n1 and n2 are bigger than root, then LCA lies in right
    if (root->data < n1->data && root->data < n2->data)
        return lca(root->right, n1, n2);
    return root;
}

int main() {
    struct node* t = newNode(9); // 9 for bst, #<9 not bst
    t->left = newNode(7);
    t->right = newNode(11);
    t->left->left = newNode(5);
    t->left->right = newNode(8);
    t->left->left->left = newNode(1);
    t->left->left->right = newNode(6);
    t->right->left = newNode(10);
    t->right->right = newNode(12);
    struct node* n1 = t->left->left->left;
    struct node* n2 = t->left->right = newNode(8);
    struct node* c = lca(t, n1, n2);
    cout<<"The common ancester is node: "<<c->data<<endl;
    getchar();
}

