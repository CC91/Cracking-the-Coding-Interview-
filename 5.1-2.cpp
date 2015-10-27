#include <iostream>
#include <vector>
// Save [0,i) bits of the N, clear [0, j] of N by shift right j+1 and shift left j+1, then OR (m<<i) OR saved [0, i) bits.
using namespace std;

void printBit(int x) {
    vector<int> v;
    int len = 8*sizeof(int);
    int mask = 1;
    while (len--) {
        if (x&mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1;
    }
    while (!v.empty()) {
        cout<<v.back();
        v.pop_back();
    }
    cout<<endl;
}

int insert(int N, int M, int i, int j) {  // j>i
    // Save [0, i) bits of the N
    int buf = N & ((1 << i)-1);
    return (N >> (j+1) << (j+1)) | (M<<i) | buf;
    
}


int main() {
    int n = 1<<10, m = 21;
    int r = insert(n, m, 2, 6);
    printBit(n);
    printBit(m);
    printBit(r);
    getchar();
}



