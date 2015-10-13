#include <iostream>
#include <cmath>
using namespace std;
// recurse through the entire tree, and for each node, compute the heights of each subtree. O(N^2) time.

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int getHeight(node* root) {
    if (root==NULL) return 0;
    
    return max(getHeight(root->left), getHeight(root->right))+1;
}

bool isBalanced(node* root) {
    if (root==NULL) return true; // base case
    int heightDiff = getHeight(root->left)-getHeight(root->right);
    if (abs(heightDiff)>1) return false;
    else return isBalanced(root->left) && isBalanced(root->right);
}


// generate a tree to test it
struct node* newNode(int data) {
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(7);
    root->right->left = newNode(6);
    root->left->right = newNode(5);
    root->left->left->left->left = newNode(10);
    
    if (isBalanced(root)) cout<<"The tree is balanced!"<<endl;
    else cout<<"The tree is not balanced!"<<endl;
}