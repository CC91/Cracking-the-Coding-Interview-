#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Tower {
private:
    stack<int> disks;
    int idx;
public:
    Tower(int i): idx(i) {}
    int index() {
        return idx;
    }
    
    void add(int d) {
        if (!disks.empty() && disks.top()<=d) cout<<"Error placing disk "<<d<<endl;
        else disks.push(d);
    }
    
    void moveTopTo(Tower &t) {
        int top = disks.top();
        disks.pop();
        t.add(top);
        cout<<"Move disk "<<top<<" from "<<index()<<" to "<<t.index()<<endl;
    }
    
    void moveDisks(int n, Tower &dest, Tower &buf) {
        if (n>0) {
            moveDisks(n-1, buf, dest);
            moveTopTo(dest);
            buf.moveDisks(n-1, dest, *this);
        }
    }
};

int main() {
    int n=5;
    vector<Tower> towers;
    for (int i=0; i<3; i++) {
        Tower t(i);
        towers.push_back(t);
    }
    for (int i=n-1; i>=0; --i) towers[0].add(i);
    towers[0].moveDisks(n, towers[2], towers[1]);
}


