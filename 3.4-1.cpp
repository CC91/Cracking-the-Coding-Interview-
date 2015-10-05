#include <iostream>
#include <stack>
using namespace std;

static stack<int> a;
static stack<int> b;
static stack<int> c;

// generate a visable Hanoi
void generateHanoi(stack<int> a, stack<int> b, stack<int> c) {
    if (a.empty()) cout<<"a is empty"<<endl;
    else {
        cout<<"current a is"<<endl;
        while (!a.empty()) {
            cout<<a.top()<<endl;
            a.pop();
        }
        //cout<<endl;
    }
    
    if (b.empty()) cout<<"b is empty"<<endl;
    else {
        cout<<"current b is"<<endl;
        while (!b.empty()) {
            cout<<b.top()<<endl;
            b.pop();
        }
        //cout<<endl;
    }
    
    if (c.empty()) cout<<"c is empty"<<endl;
    else {
        cout<<"current c is"<<endl;
        while (!c.empty()) {
            cout<<c.top()<<endl;
            c.pop();
        }
        //cout<<endl;
    }
    cout<<"--------------"<<endl;
}

// move one disk from origin to destination
void move(stack<int>& ori, stack<int>& dest) {
    if (ori.empty()) {
        cout<<"Nothing to be moved!"<<endl;
        return;
    }
    int tmp = ori.top();
    if (!dest.empty() && tmp >= dest.top()) {
        cout<<"Can't place the current disk on a smaller disk!"<<endl;
        return;
    }
    ori.pop();
    dest.push(tmp);
    generateHanoi(a, b, c);
}

// the order is origin, destination and buffer
void hanoi(int n, stack<int>& ori, stack<int>& dest, stack<int>& buf) {
    if (n<=0) return;
    
    // move top (n-1) disks from origin to buffer, using destination as a buffer
    hanoi(n-1, ori, buf, dest);
    
    // move nth disk from origin to destination
    move(ori, dest);
    
    // move top (n-1) disks from buffer to destination, using origin as a buffer
    hanoi(n-1, buf, dest, ori);
}


int main() {
    int n = 3;
    for (int i=n; i>0; i--) a.push(i);
    generateHanoi(a, b, c);
    hanoi(n, a, c, b);
}







