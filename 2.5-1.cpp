#include <iostream>
#include <string>
using namespace std;
// digits are stored in reverse order
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

ListNode *numAdd(ListNode *head1, ListNode *head2){
    if (!head1&&!head2) return NULL;
    ListNode *p1 = head1;
    ListNode *p2 = head2;
    ListNode *head = NULL;
    ListNode *dummy = new ListNode();
    
    int dig=0;
    int c=0;
    while (p1 || p2) {
        dig = c + (p1?p1->val:0) + (p2?p2->val:0);
        c = (dig>9)?1:0;
        dig = dig%10;
        ListNode *tmp = new ListNode();
        tmp->val = dig;
        if (!head) {
            head = tmp;
            dummy->next = head;
        }
        else {
            head->next = tmp;
            head = tmp;
        }
        p1?(p1=p1->next):0;
        p2?(p2=p2->next):0;
        
    }
    // if the summed result has more digits than both of addends we need the carrier
    if (c) {
        ListNode *last = new ListNode();
        last->val = c;
        head->next = last;
        last->next = NULL;
    }
    return dummy->next;
}



int main() {
    int l1[] = {4,5,9};
    int l2[] = {2,5};
    ListNode *h1 = initList(l1, 3);
    ListNode *h2 = initList(l2, 2);
    
    ListNode *newList = numAdd(h1, h2);
    while (newList) {
        cout << newList->val <<endl;
        newList = newList->next;
    }
}



