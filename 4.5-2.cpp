#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// inorder traverse the binary tree, track the last value and compare it with next value

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

// inorder traversal & check

int lastVal=0;
bool inorderCheck(node* root) {
    if (root==NULL) return true; // base case
    
    // recur on left
    if (!inorderCheck(root->left)) return false;
    
    // compare last value to current value
    if (root->data <= lastVal) return false;
    lastVal = root->data;
    
    // recur on right
    if (!inorderCheck(root->right)) return false;
    
    return true; // all fine
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
    cout<<inorderCheck(t)<<endl;
}



