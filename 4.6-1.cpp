#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;
// In BST every node's value is >= its left subtrees' values and < its right subtrees'. After traversing the tree inorder, the value shoulbe sorted, the node's next node will be the least one among nodes that are bigger than the current node. If the current node has right child, its next node would be its right child's leftmost child, otherwise we need to keep going up and check the node's ancester until find a node that is bigger than the current node.

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
    
    // if it has no right subtree, then next node is one of the ancesters, go up using the parent pointer until you get a node which is left child of it's parent, the parent of such a node is the next node or the parent of the current node is the next node
    struct node* p = n->parent;
    while (p && n==p->right) {
        n=p;
        p=p->parent;
    }
    return p;
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

// time complexity: O(h), h is the height of the tree
