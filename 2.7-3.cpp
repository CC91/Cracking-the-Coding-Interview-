#include <iostream>
#include <string>
#include <stack>
using namespace std;
// iterative approach, scan the list to get the length

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

bool palin(ListNode *head) {
    if (!head || !head->next) return true;
    ListNode *slow = head;
    ListNode *fast = head;
    stack<int> s;
    s.push(head->val);
    while (fast->next && fast->next->next) {
        slow = slow->next;
        s.push(slow->val);
        fast = fast->next->next;
    }
    if (!fast->next) s.pop(); // if there is odd number of nodes
    while (slow->next) { // include the condition when there are just 2 nodes
        int tmp = s.top(); s.pop();
        slow = slow->next;
        if (tmp != slow->val) return false;
    }
    return true;
}


int main() {
    int test[] = {9,2,1,5,1,2,9};
    ListNode *head = initList(test, 7);
    int a = palin(head);
    cout<<a<<endl;
}



