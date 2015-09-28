#include <iostream>
using namespace std;
// use node to realize dynamic stacks

struct node{
    int val;
    int prev; // remember the last element so that we can still have the position of the pointer after we pop the current element
};

class stack {
public:
    stack(int size = 300) {
        buf = new node[size];
        for (int i=0; i<size;i++) // prev is -10 which means available array space
            buf[i].prev = -10;
        sec[0] = sec[1] = sec[2] = -1; // sec is the stack pointer
        this->size = size;
        cur = 0;
    }
    ~stack() {
        delete [] buf;
    }
    
    void push(int stackNum, int val) {
        if (cur == size) return;
        buf[cur].val = val;
        buf[cur].prev = sec[stackNum];
        sec[stackNum] = cur;
        while (cur<size && buf[cur].prev != -10) {
            ++cur;
        }
    }
    
    void pop(int stackNum) {
        if(empty(stackNum)) return;
        cur = sec[stackNum];
        sec[stackNum] = buf[sec[stackNum]].prev;
    }
    
    int top(int stackNum) {
        if (empty(stackNum)) return -1;
        return buf[sec[stackNum]].val;
    }
    
    bool empty(int stackNum) {
        return sec[stackNum] == -1;
    }
    
private:
    node *buf;
    int sec[3];
    int size;
    int cur;
};

int main() {
    stack s;
    for (int i=0; i<10; i++)
        s.push(0, i);
    for (int i=10; i<20; i++)
        s.push(1, i);
    for (int i=150; i<160; i++)
        s.push(2, i);
    
    for (int i=0; i<3; i++)
        cout<<s.top(i)<<" ";
    cout<<endl;
    
    for (int i=0; i<3; i++) {
        s.pop(i);
        cout<< s.top(i)<<" ";
    }
    cout<<endl;
    
    s.push(0, 12);
    s.push(1, 170);
    s.push(2, 180);
    for (int i=0; i<3; ++i)
        cout<<s.top(i)<<" ";
    cout<<endl;
    return 0;
}







