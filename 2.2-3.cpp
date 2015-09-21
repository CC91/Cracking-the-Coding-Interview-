#include <iostream>
#include <string>
using namespace std;
// Iterative version

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


void k2last(ListNode *head, int k) {
    if (!head) return;
    ListNode *slow=head;
    ListNode *fast=head;
    for (int i=0; i<k-1; i++) fast = fast->next; // fast pointer advances slow pointer by n-1 steps
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    cout<<slow->val<<endl;
}

int main() {
    int test[] = {1,2,3,2,3,4,1,5,7,34,524};
    int n = 11;
    ListNode *head = initList(test, n);
    k2last(head, 0);
    return 0;
}
