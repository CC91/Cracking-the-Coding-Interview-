#include <iostream>
#include <list>
using namespace std;
// The middle element of the array is the root, for each subarray it would be the similar pattern. Insert left subarray to the left subtree, insert right subarray to the right subtree. And then recurse.

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data);

struct node* BST(int arr[], int s, int d) {
    if (s>d) return NULL; // base case
    int mid = (s+d)/2;
    struct node* root = newNode(arr[mid]);
    root->left = BST(arr, s, mid-1);
    root->right = BST(arr, mid+1, d);
    return root;
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// print preorder traversal of the tree
void print(struct node* root) {
    if (!root) return;
    cout<<root->data<<endl;
    print(root->left);
    print(root->right);
}

int main() {
    int t[]={1,2,3,4,5,6,7};
    int n=sizeof(t)/sizeof(t[0]);
    struct node* root = BST(t, 0, n-1);
    print(root);
}