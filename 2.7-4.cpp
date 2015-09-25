#include <iostream>
#include <string>
#include <stack>
using namespace std;
// recursive approach, compare the two side of the list until reach the middle node
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

bool palin(ListNode *&head, ListNode *last) {
    if (!last) return true;
    bool res = palin(head, last->next);
    if (res) res = (head->val == last->val);
    head = head->next;
    return res;
}

int main() {
    int test[] = {2,1,1,1,1,2};
    ListNode *head = initList(test, 6);
    ListNode *last = head;
    cout<<palin(head, last)<<endl;
}









