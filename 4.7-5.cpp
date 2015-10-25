#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
// Not necessarily a BST, no map/hashtable
// Without links to parents.
// If n1 and n2 are both on the left of the node, branch left to look for the common ancester, if they are both on the right,
// branch right to look for the common ancester. When n1 and n2 are no longer on the same side, you must have found the first
// common ancester.

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

// returns true if n1 is a descendent of root
bool covers(struct node* root, struct node* n1) {
    if (!root) return false;
    if (root == n1) return true;
    return covers(root->left, n1) || covers(root->right, n1);
}

// check if n1 and n2 are on same side
struct node* lcaHelper(struct node* root, struct node* n1, struct node* n2) {
    if (!root) return NULL;
    if (root==n1 || root==n2) return root;
    bool n1_on_left = covers(root->left, n1);
    bool n2_on_left = covers(root->left, n2);

    
    // if n1 and n2 are on different sides, return root
    if (n1_on_left != n2_on_left) return root;
    
    // else they are on same side, traverse this side
    struct node* childSide = n1_on_left ? root->left : root->right;
    return lcaHelper(childSide, n1, n2);
}

struct node* lca(struct node* root, struct node* n1, struct node* n2) {
    if (!covers(root, n1) || !covers(root, n2)) return NULL; // error check
    return lcaHelper(root, n1, n2);
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

// O(n) time on a balanced tree. Because covers is called on 2n nodes in the first call (n nodes for left side and no nodes for
// right side). After that, it branches left or right, at which point covers will be called on 2n/2 nodes, then 2n/4 nodes and so on.
// This results in a runtime of O(n).

