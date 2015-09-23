#include <iostream>
#include <string>
using namespace std;
// digits are stored in forward order, scan two lists, use recursion.
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

int getLength (ListNode *head) {
    ListNode *p = head;
    int len = 0;
    while (p) {
        ++len;
        p = p->next;
    }
    return len;
}

ListNode *insert0s(ListNode *head, int n) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    for (int i=0; i<n; i++) {
        ListNode *tmp = new ListNode();
        tmp->val = 0;
        cur->next = tmp;
        cur = cur->next;
    }
    cur->next = head;
    return dummy->next;
}

ListNode *addition(ListNode *head1, ListNode *head2, int &c) {
    if (!head1&&!head2) return NULL;
    ListNode *head = addition(head1->next, head2->next, c);
    int dig = c + head1->val +head2->val;
    ListNode *res = new ListNode();
    res->val = dig%10;
    res->next = head;
    c = dig/10;
    return res;
}

ListNode *numAdd(ListNode *head1, ListNode *head2){
    int c=0;
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    if (l1>l2) head2 = insert0s(head2, l1-l2);
    if (l1<l2) head1 = insert0s(head1, l2-l1);
    ListNode *list = addition(head1, head2, c);
    if (c) {
        ListNode *tmp = new ListNode();
        tmp->val = c;
        tmp->next = list;
        list = tmp;
    }
    return list;
}


int main() {
    int l1[] = {9,5,4};
    int l2[] = {5,2};
    ListNode *h1 = initList(l1, 3);
    ListNode *h2 = initList(l2, 2);
    ListNode *newList = numAdd(h1, h2);
    while (newList) {
        cout << newList->val <<endl;
        newList = newList->next;
    }
}



