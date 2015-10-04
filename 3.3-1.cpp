#include <iostream>
using namespace std;
// No popAt() version
// SetOfStacks is an array of stacks, the pointer curStack points to the current stack.
static const int MAX = 100;
static const int NUM = 5;

class stack {
private:
    int *buf;
    int threshold;
    int cur;
public:
    stack(int vol = MAX) {
        buf = new int[vol];
        cur = -1;
        threshold = vol;
    }
    ~stack() {
        delete [] buf;
    }
    
    bool isEmpty() {
        if (cur == -1) return true;
        return false;
    }

    bool isFull() {
        if (cur == threshold-1) return true;
        return false;
    }

    void pop() {
        --cur;
    }
    
    int top() {
        return buf[cur];
    }
    
    void push(int val) {
        buf[++cur] = val;
    }
};


class SetOfStacks {
private:
    stack *s;
    int curStack;
    int threshold;
public:
    SetOfStacks(int vol = NUM) {
        s = new stack[vol];
        curStack = 0;
        threshold = vol;
    }
    ~SetOfStacks() {
        delete[] s;
    }
    
    bool isEmpty() {
        if (curStack == 0) return s[0].isEmpty();
        return false;
    }
    
    bool isFull() {
        if (curStack == threshold-1) return s[curStack].isFull();
        return false;
    }
    
    void pop() {
        if (s[curStack].isEmpty()) --curStack;
        s[curStack].pop();
    }
    
    int top() {
        if (s[curStack].isEmpty()) --curStack; //check is current stack is empty
        return s[curStack].top();
    }
    
    void push(int val) {
        if (s[curStack].isFull()) ++curStack; //check if current stack is full
        s[curStack].push(val);
    }
    
};

int main() {
    SetOfStacks test;
    for(int i=0; i<=3*MAX; ++i) test.push(i);
    while (!test.isEmpty()) {
        cout<<test.top()<<endl;
        test.pop();
    }
}







