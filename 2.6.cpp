#include <iostream>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};

ListNode *initList(int m[], int n, int x[], int y) {
    ListNode *head = NULL, *tmp = NULL;
    // linked list
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
    
    // cicular list
    ListNode *Head = NULL, *Tmp = NULL;
    for (int i=0; i<y; i++) {
        ListNode *Node = new ListNode();
        Node->val = x[i];
        if (i==0) {
            Head = Node;
            Tmp = Node;
        }
        Tmp->next = Node;
        Tmp = Node;
    }
    Tmp->next = Head;
    tmp->next = Head;
    return head;
}

ListNode *findBegin(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    // find meeting point in the loop
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            break;
        }
    }

    
        // error check, no meeting point so no loop
        if (!fast || !fast->next) {
            return NULL;
        }
        
        // move slow to head, let fast and slow move at same pace, they will meet at loop start
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    return fast;
}




int main() {
    int l1[] = {1,2,1,5,7,8,3,2};
    int l2[] = {99,4,6,8,4,3,2,9,3,6,7};
    ListNode *test = initList(l1, 8, l2, 11);
    ListNode *found = findBegin(test);
    cout << found->val <<endl;
}



