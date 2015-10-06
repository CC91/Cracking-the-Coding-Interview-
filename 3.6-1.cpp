#include <iostream>
#include <stack>
using namespace std;

class sortS {
private:
    stack<int> s1, s2;
public:
    void push(int val) {
        s1.push(val);
    }
    
    void pop() {
        while (!s1.empty()) {
            int tmp = s1.top();
            s1.pop();
            while (!s2.empty() && tmp<s2.top()) {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(tmp);
        }
        s2.pop();
    }
    
    int peek() {
        while (!s1.empty()) {
            int tmp = s1.top();
            s1.pop();
            while (!s2.empty() && tmp< s2.top()) {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(tmp);
        }
        return s2.top();
    }
    
    bool isEmpty() {
        if (s1.empty() && s2.empty()) return true;
        else return false;
    }
    
};

int main() {
    sortS test;
    test.push(10);
    test.push(1);
    test.push(2);
    test.push(3);
    cout<<"The top value is: "<<test.peek()<<endl;
    cout<<"Is it empty? (0/1) "<<test.isEmpty()<<endl;
    test.pop();
    while (!test.isEmpty()) {
        cout<<test.peek()<<" ";
        test.pop();
    }
    cout<<endl;
    return 0;
}