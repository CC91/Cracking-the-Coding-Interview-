#include <iostream>
using namespace std;
// use 2 stacks, one to store pushed elements, one to store minimum.

class stack {
private:
    static const int max = 100;
    int s[max];
    int top;
    
public:
    stack() {top = -1;}
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
};

bool stack::isEmpty() {
    if (top == -1) return true;
    return false;
}

bool stack::isFull() {
    if (top == max-1) return true;
    return false;
}

int stack::pop() {
    int val = s[top];
    top--;
    return val;
}

void stack::push(int x) {
    top++;
    s[top] = x;
}

class stackMin: public stack {
    stack minS;
public:
    int pop();
    void push(int x);
    int getMin();
};

void stackMin::push(int x) {
    if (isEmpty()==true) {
        stack::push(x);
        minS.push(x);
    }
    else {
        stack::push(x);
        int tmp = minS.pop();
        minS.push(tmp);
        if (x < tmp) minS.push(x);
        else minS.push(tmp);
    }
}

int stackMin::pop() {
    int val = stack::pop();
    minS.pop();
    return val;
}

int stackMin::getMin() {
    int val = minS.pop();
    minS.push(val);
    return val;
}
int main() {
    stackMin test;
    test.push(3);
    test.push(50);
    test.push(1);
    test.push(7);
    test.push(12);
    cout << test.getMin() <<endl;
    test.push(0);
    cout << test.getMin() <<endl;
}







