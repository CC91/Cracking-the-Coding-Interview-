#include <iostream>
#include <string>
using namespace std;
// reverse the list and compare

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

ListNode *reverse(ListNode *head) {
    ListNode *dummy = new ListNode();
    dummy->next = head;
    while (head->next) {
        ListNode *tmp = head->next;
        head->next = head->next->next;
        tmp->next = dummy->next;
        dummy->next = tmp;
    }
    return dummy->next;
}

void palin(ListNode *head) {
    ListNode *RL = reverse(head);
    ListNode *p1 = head;
    ListNode *p2 = RL;
    while (p1) {
        if (p1->val == p2->val) {
            p1 = p1->next;
            p2 = p2->next;
        }
        else {
            cout<< "The list is not a palindrome!" << endl;
            break;
        }
    }
    
    while (RL) {
        cout << RL->val<<endl;
        RL = RL->next;
    }
    cout << "The list is a palindrome!" << endl;
}




int main() {
    int test[] = {9,2,1,5,5,1,2,9};
    ListNode *head = initList(test, 8);
    palin(head);
}



