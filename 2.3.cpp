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
    int i=0;
    while (i!=n/2) {
        head = head->next;
        ++i;
    }
    return head;
}


void delMiddle(ListNode *mid) {
    ListNode *p = mid->next;
    while (mid->next) {
        mid->val = p->val;
        mid = mid->next;
        if (p->next == NULL) {
            mid->next = NULL; // delete the last node
            delete p;
        }
        else p = p->next;
        cout << mid->val << endl;
    }
    
}

int main() {
    int test[] = {1,2,3,2,3,4,1,5,7,34,524};
    int n = 11;
    ListNode *m = initList(test, n);
    delMiddle(m);
    return 0;
}
