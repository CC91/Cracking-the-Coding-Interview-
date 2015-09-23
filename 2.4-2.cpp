#include <iostream>
#include <string>
using namespace std;
// get the length and the last node of the list
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
    ListNode *tmp = head;
    int len=1;
    while (tmp->next) {
        ++len;
        tmp = tmp->next;
    }
    ListNode *last = tmp;
    
    ListNode *dummy = new ListNode();
    dummy->next = head;
    
    while (len-1) {
        if (dummy->next->val < x) {
            dummy = dummy->next;
        }
        else {
            ListNode *newL = new ListNode();
            newL->val = dummy->next->val;
            last->next =newL;
            last = last->next;
            dummy->next = dummy->next->next;
        }
        --len;
    }
    return head;
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



