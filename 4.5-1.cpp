#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// inorder traverse the binary tree and copy it to an array and then check if it is sorted
// array is inefficient, we need to initialize it with enough space...

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

// inorder traversal

int idx=0; // index for array!
void inorderCopy(node* root, int arr[]) {
    if (root==NULL) return; // base case
    
    // recur on left
    inorderCopy(root->left, arr);
    arr[idx]=root->data;
    idx++;
    
    // recur on right
    inorderCopy(root->right, arr);
}


bool checkArray(node* root) {
    int array[20]; // waste space here...
    inorderCopy(root, array);
    for (int i=1; i<idx; i++)
        if (array[i]<= array[i-1]) {
            cout<< "It is not a BST."<<endl;
            return 0;
        }
    cout<<"It is a BST."<<endl;
    return true;
}

int main() {
    struct node* t = newNode(9);
    t->left = newNode(7);
    t->right = newNode(11);
    t->left->left = newNode(5);
    t->left->right = newNode(8);
    t->left->left->left = newNode(1);
    t->left->left->right = newNode(6);
    t->right->left = newNode(10);
    t->right->right = newNode(12);
    checkArray(t);
    return 0;
}



