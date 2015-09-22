#include <iostream>
#include <string>
using namespace std;
// shift the node is annoying so just create two new list, one is for values <x and the other for values > x

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *initList(int m[], int n) {
    ListNode *head = NULL, *tmp = NULL;
    
    for (int i=0; i<n; i++) {
        ListNode *node = new ListNode();
        node->val = m[i];
        if (i==0) {
            head = node;
            tmp = node;
        }
        tmp->next = node;
        tmp = node;
    }
    return head;
}


ListNode *partitionX(ListNode *head, int x) {
    if (!head) return head;
    ListNode *n1 = new ListNode();
    ListNode *n2 = new ListNode();
    ListNode **p1 = &n1;
    ListNode **p2 = &n2;
    
    while (head) {
        if (head->val < x) {
            (*p1)->next = head;
            p1 = &(*p1)->next;
        }
        else {
            (*p2)->next = head;
            p2 = &(*p2)->next;
        }
        head = head->next;
    }
    (*p2)->next = NULL;
    (*p1)->next = n2->next;
    return n1->next;
}

int main() {
    int test[] = {1,4,3,2,5,2};
    int n = 6;
    ListNode *head = initList(test, n);
    ListNode *newList = partitionX(head, 3);
    while (newList) {
        cout << newList->val <<endl;
        newList = newList->next;
    }
}



