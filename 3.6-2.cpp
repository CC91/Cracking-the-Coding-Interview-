#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// use 1 stack and a priority queue

void sortS(stack<int> &s1) {
    priority_queue<int, vector<int>, greater<int>> q;
    while (!s1.empty()) {
        q.push(s1.top());
        s1.pop();
    }
    while (!q.empty()) {
        s1.push(q.top());
        q.pop();
    }
}


int main() {
    stack<int> test;
    test.push(10);
    test.push(5);
    test.push(2);
    test.push(3);
    sortS(test);
    test.pop();
    while (!test.empty()) {
        cout<<test.top()<<" ";
        test.pop();
    }
    cout<<endl;
    return 0;
}