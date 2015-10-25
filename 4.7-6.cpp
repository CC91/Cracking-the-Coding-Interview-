#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// Not necessarily a BST, no map/hashtable
// Without links to parents.
// Optimized: no need to search all nodes under root for n1 and n2 via covers, we can search the entire tree once t find
// n1 and n2, then bubble up the findings to earlier nodes in the stack. Basic logic is the same as the last soulution.
// Function returns the followings:
// 1) return n1, if root's usbtree includes n1 (and not n2)
// 2) return n2, if root's subtree includes n2 (and not n1)
// 3) return null, if neither n1 nor n2 are in root's subtree
// 4) else, return the common ancester of n1 and n2

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

struct node* lca(struct node* root, struct node* n1, struct node* n2) {
    if (!root) return NULL;
    if (root==n1 || root==n2) return root;
    
    struct node* x=lca(root->left, n1, n2);
    if (x && x!=n1 && x!=n2) return x; // already found common ancester
    
    struct node* y=lca(root->right, n1, n2);
    if (y && y!=n1 && y!=n2) return y; // already found common ancester
    
    if (x && y) return root; // n1 and n2 found in different subtrees, and also found the common ancester
    else if (root==n1 || root==n2) return root;
    else return x==NULL?y:x; // if either x or y is null, return the non-null
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
    struct node* n2 = t->left->right;
    struct node* c = lca(t, n1, n2);
    cout<<"The common ancester is node: "<<c->data<<endl;
    getchar();
}


