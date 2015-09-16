#include <iostream>
#include <string>
#include <map>
using namespace std;

// hash table
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
    ListNode *pre = NULL;
    ListNode *cur = head;
    map<int, bool> table;
    while (cur) {
        
        // if duplicated
        if (table[cur->val]) pre->next = cur->next;
        else {
            table[cur->val] = true;
            pre = cur;
        }
        cur = cur->next;
    }
}


int main() {
    int n = 15;
    int test[] = {1,2,4,3,1,5,2,3,9,2,0,0,6,8,4};
    ListNode *head = initList(test, n);
    Print(head);
    removeDuplicates(head);
    Print(head);
}
