#include <iostream>
#include <string>
using namespace std;

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

void Print(ListNode *head) {
    cout << "Linked list is: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void removeDuplicates(ListNode *head) {
    if (!head) return;
    ListNode *cur = head;
    while (cur) {
        ListNode *fast = cur;
        while (fast->next) {
            if (cur->val == fast->next->val) fast->next = fast->next->next;
            else fast = fast->next;
        }
        cur = cur->next;
    }
}


int main() {
    int n = 10;
    int test[] = {1,2,4,3,1,5,2,3,9,2};
    ListNode *head = initList(test, n);
    Print(head);
    removeDuplicates(head);
    Print(head);
}
