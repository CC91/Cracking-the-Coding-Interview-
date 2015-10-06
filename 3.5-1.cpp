#include <iostream>
#include <stack>
using namespace std;
// use 2 stacks

class myQ {
private:
    stack<int> in, out;
public:
    
    int front() { // in order to get the front value we need move all the elements from stack in to stack out and then move them back
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
        int res = out.top();
        
        while (!out.empty()) {
            in.push(out.top());
            out.pop();
        }
        return res;
    }
    
    int back() {
        return in.top();
    }
    
    void push(int val) {
        in.push(val);
    }
    
    void pop() { // similar as function front, we move all elements from stack in to out to get the firstmost value and pop it, then move the rest back
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
        out.pop();
        while (!out.empty()) {
            in.push(out.top());
            out.pop();
        }
    }
    
};


int main() {
    myQ test;
    cout<<"The queue is: "<<endl;
    for (int i=0; i<10; i++) cout<<i<<" ";
    cout<<endl;
    for (int i=0; i<10; i++) test.push(i);
    cout<<"Front val is: "<<test.front()<<endl;
    cout<<"Back val is: "<<test.back()<<endl;
    test.pop();
    cout<<"After poping: "<<endl;
    cout<<"Front val is: "<<test.front()<<endl;
    cout<<"Back val is: "<<test.back()<<endl;
}


