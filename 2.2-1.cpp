#include <iostream>
#include <string>
using namespace std;
// If the length of the linked list n is known, the target element in order is (n-k)

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


void k2last (ListNode *head, int n, int k) {
    if (!head) return;
    ListNode *ele = head;
    if (k==0) {
        for (int i=0; i<n-1; i++) {
            ele = ele->next;
        }
    }
    else {
        for (int i=0; i!=n-k; i++) {
            ele = ele->next;
        }
    }
    cout << ele->val << endl;
}

int main() {
    int test[] = {1,2,3,2,3,4,1,5,7,34,524};
    int n = 11;
    ListNode * head = initList(test, n);
    k2last(head, n, 0);
    return 0;
}
