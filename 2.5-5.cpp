#include <iostream>
#include <string>
using namespace std;
// reverse the forward ordered list and follow the method as the reverse order, and reverse the result
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

// recursively reverse the list
ListNode *reverse(ListNode *head) {
    // revursive base case
    ListNode *p = head;
    if (p->next==NULL) return head;
    head = reverse(p->next);
    p->next->next = p;
    p->next = NULL;
    return head;
}




ListNode *numAdd(ListNode *head1, ListNode *head2){
    if (!head1&&!head2) return NULL;
    ListNode *h1 = reverse(head1);
    ListNode *h2 = reverse(head2);
    ListNode *p1 = h1;
    ListNode *p2 = h2;
    ListNode *head = NULL;
    ListNode *dummy = new ListNode();
    
    int dig = 0;
    int c = 0;
    while (p1||p2) {
        dig = c+(p1?p1->val:0)+(p2?p2->val:0);
        c=dig/10;
        dig = dig%10;
        ListNode *tmp = new ListNode();
        tmp->val = dig;
        // if it is the head
        if (!head) {
            head = tmp;
            dummy->next  = head;
        }
        else {
            head->next = tmp;
            head=tmp;
        }
        p1?(p1=p1->next):0;
        p2?(p2=p2->next):0;
    }
    
    if (c) {
        ListNode *last = new ListNode();
        last->val = c;
        head->next = last;
        last->next = NULL;
    }
    
    ListNode *list = dummy->next;
    return reverse(list);
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



