#include <iostream>
#include <list>
#include <vector>
using namespace std;
// BFS, iterate through the root first, then level 2,3,...
struct tree {
    tree(int val):right(0), left(0), value(val) {}
    int value;
    tree* left;
    tree* right;
};

// create a tree
void insert(tree* &node, int val) {
    if (node==NULL) node = new tree(val);
    else if (val<node->value) insert(node->left, val);
    else insert(node->right, val);
}

void traverse(tree *node) {
    vector<list<tree*>> linked;
    int level=0;
    list<tree*> l;
    l.push_back(node);
    linked.push_back(l);
    while (!linked[level].empty()) {
        list<tree*> L;
        list<tree*>::iterator itr;
        for (itr=linked[level].begin(); itr!=linked[level].end(); itr++) {
            tree *p=*itr;
            if (p->left) L.push_back(p->left);
            if (p->right) L.push_back(p->right);
        }
        level++;
        linked.push_back(L);
        }
    // print out the linked lists
    vector<list<tree*>>::iterator it;
    for (it=linked.begin(); it!=linked.end(); it++) {
        list<tree*> t=*it;
        list<tree*>::iterator iit;
        for (iit=t.begin(); iit!=t.end(); iit++) {
            tree *n=*iit;
            cout<<n->value<<" ";
        }
        cout<<endl;
    }
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
    traverse(test);
}