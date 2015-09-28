#include <iostream>
using namespace std;
// divide the array into 3 sections as 3 stacks

class stack {
public:
    stack(int size = 100) {
        buf = new int[size*3];
        sec[0] = sec[1] = sec[2] = -1; // sec is the stack pointer
        this->size = size;
    }
    ~stack() {
        delete [] buf;
    }
    
    void push(int stackNum, int val) {
        int index = stackNum*size +sec[stackNum] +1;
        sec[stackNum]++; // increment stack pointer and then update top value
        buf[index] = val;
    }
    
    void pop(int stackNum) {
        sec[stackNum]--; // decrement pointer
    }
    
    int top(int stackNum) {
        int index = stackNum*size + sec[stackNum];
        return buf[index];
    }
    
    bool empty(int stackNum) {
        return sec[stackNum] == -1;
    }
    
private:
    int *buf;
    int sec[3];
    int size;
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







