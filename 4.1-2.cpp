#include <iostream>
#include <cmath>
using namespace std;

// Improved method works by checking the height of each subtree as we recurse down from the root. On each node, we recursively get the heights of the left and right subtrees through the checkHeight method. If the subtree is balanced then chekHeight will return the actual height of the subtree. If the subtree is not balanced, then checkHeight will return -1. We will immediately break and return -1 from the current call.
// O(N) time and O(H) space, H is the height of the tree.
struct node {
    int data;
    struct node* left;
    struct node* right;
};

int checkHeight(node* root) {
    if (root==NULL) return 0;
    
    // check if left is balanced
    int leftHeight = checkHeight(root->left);
    if (leftHeight==-1) return -1; //not balanced
    
    // check if right is balanced
    int rightHeight = checkHeight(root->right);
    if (rightHeight==-1) return -1; // not balanced
    
    // check if current node is balanced
    int heightDiff = leftHeight-rightHeight;
    if (abs(heightDiff)>1) return -1; // not balanced
    else return max(leftHeight, rightHeight)+1; // return height
}

bool isBalanced(node* root) {
    if (checkHeight(root)==-1) return false;
    else return true;
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
    //root->left->left->left->left = newNode(10);
    
    if (isBalanced(root)) cout<<"The tree is balanced!"<<endl;
    else cout<<"The tree is not balanced!"<<endl;
}