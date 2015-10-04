#include <iostream>
using namespace std;
// With popAt() version, we don't roll over the space of removed elements by popAt() funtion.
// Therefore before the curStack pointer, there might be empty space. For function isEmpty(), top(),
// pop(), popAt(), we need to check if the curStack is empyty & before the curStack is empty or not.
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
        while (s[curStack].isEmpty() && curStack != -1) --curStack;
        if (curStack == -1) return true;
        return false;
    }
    
    bool isFull() {
        if (curStack == threshold-1) return s[curStack].isFull();
        return false;
    }
    
    void pop() {
        while (s[curStack].isEmpty()) --curStack;
        s[curStack].pop();
    }
    
    void popAt(int x) {
        while (s[x].isEmpty()) --x;
        s[x].pop();
    }
    
    int top() {
        while (s[curStack].isEmpty()) --curStack; //check is current stack is empty
        return s[curStack].top();
    }
    
    void push(int val) {
        if (s[curStack].isFull()) ++curStack; //check if current stack is full
        s[curStack].push(val);
    }
    
};

int main() {
    SetOfStacks test;
    for(int i=1; i<=3*MAX; ++i) test.push(i);
    for (int i=0; i<MAX; ++i) {
        test.popAt(0);
        test.popAt(1);
    }
    test.popAt(3);
    while (!test.isEmpty()) {
        cout<<test.top()<<endl;
        test.pop();
    }
}







