#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <climits>

using namespace std;
// Recure through each node, pass the function the full path from root to n. This function then adds
// the nodes along the path in reverse order from n to root. When the sum of each subpath equals sum,
// then print this path.
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

void print(int path[], int start, int end) {
    for (int i=start; i<=end; i++) cout<<path[i]<<" ";
    cout<<endl;
}

int depth(struct node* node) {
    if (!node) return 0; // base case
    else return 1+max(depth(node->left), depth(node->right));
}

void findSum(struct node* node, int sum, int path[], int level) {
    if (!node) return; // base case
    
    // insert current node into path
    path[level] = node->data;
    
    // look for paths with a sum that ends at this node
    int t=0;
    for (int i=level; i>=0; i--) {
        t = t+path[i];
        if (t==sum)
            print(path, i, level);
    }
    
    // search nodes beneath this one
    findSum(node->left, sum, path, level+1);
    findSum(node->right, sum, path, level+1);
    
    // remove current node from path, not necessary
    path[level] = INT_MIN;
}

void findSum(struct node* node, int sum) {
    int d = depth(node);
    int path[d];
    findSum(node, sum, path, 0);
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
    findSum(t, 30);
    getchar();
}

// Space complexity is O(log n), since the function will recurse O(long n) times,
// time complexity is O(nlog(n)) since there are n nodes doing an average of log(n)
// amount of work on each step.

