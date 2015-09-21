#include <iostream>
#include <string>
using namespace std;
// Recursive version

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
    if (!head) return; // base case when reach the end of linked list
    if (k==0) {
        while(head->next) {
            head = head->next;
        }
        cout<< head->val<<endl;
    }
    static int i=0;
    if (!head) return; // base case when reach the end of linked list
    k2last(head->next, k); // head pointer is advanced
    if (++i==k) cout<<head->val<<endl;
}

int main() {
    int test[] = {1,2,3,2,3,4,1,5,7,34,524};
    int n = 11;
    ListNode *head = initList(test, n);
    k2last(head, 0);
    return 0;
}
