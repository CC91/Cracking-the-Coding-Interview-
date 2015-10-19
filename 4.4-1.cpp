#include <iostream>
#include <list>
#include <vector>
using namespace std;
// DFS, pre-order traversal, pass in level+1 to the next recursive call.

struct tree {
    tree(int val):right(0), left(0), value(val) {}
    int value;
    tree* left;
    tree* right;
};

typedef vector<tree* > listNodes;
vector<listNodes> arrNodes;

// create a tree
void insert(tree* &node, int val) {
    if (node==NULL) node = new tree(val);
    else if (val<node->value) insert(node->left, val);
    else insert(node->right, val);
}

void traverse(tree *node, int level) {
    if (node==NULL) return; // base case, if reach the leaf node, we return
    
    if (arrNodes.size()==level) arrNodes.push_back(listNodes());
    arrNodes[level].push_back(node);
    traverse(node->left, level+1);
    traverse(node->right, level+1);
    
}

int main() {
    tree* test = new tree(10);
    insert(test, 1);
    insert(test, 5);
    insert(test, 20);
    insert(test, 4);
    insert(test, 0);
    insert(test, 9);
    insert(test, 15);
    insert(test, 12);
    insert(test, 60);
    insert(test, 7);
    int level=0;
    traverse(test, level);
    for (int i=0; i<arrNodes.size(); i++) {
        for (int j=0; j<arrNodes[i].size(); j++)
            cout<<arrNodes[i][j]->value<<" ";
        cout<<endl;
    }
}