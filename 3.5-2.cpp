#include <iostream>
#include <stack>
using namespace std;
// use 2 stacks, but only move elements between in and out when doing back&push on in, front&pop on out

class myQ {
private:
    stack<int> in, out;
public:
    
    int front() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    int back() {
        if (in.empty()) {
            while (!out.empty()) {
                in.push(out.top());
                out.pop();
            }
        }
        return in.top();
    }
    
    void push(int val) {
        in.push(val);
    }
    
    void pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        out.pop();
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


