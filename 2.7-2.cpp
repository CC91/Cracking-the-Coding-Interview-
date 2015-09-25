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

int getLength(ListNode *head) {
    ListNode *p = head;
    int len=0;
    while (p) {
        ++len;
        p = p->next;
    }
    return len;
}

bool palin(ListNode *head) {
    int len = getLength(head);
    ListNode *p = head;
    stack<int> s;
    for (int i=1; i<len/2; i++){
        s.push(p->val);
        p = p->next;
    }

    if (len%2!=0) p=p->next;
    while (!s.empty()) {
        p = p->next;
        int tmp = s.top(); s.pop();
        if (tmp != p->val) return false;
    }
    return true;
}


int main() {
    int test[] = {9,2,1,5,1,2,9};
    ListNode *head = initList(test, 8);
    int a = palin(head);
    cout<<a<<endl;
}



