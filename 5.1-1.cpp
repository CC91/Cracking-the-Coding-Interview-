#include <iostream>
#include <vector>
// Clear the bits j through i in N, shift M so that it lines up with bits j through i, merge M and N via OR
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
    // Create a mask to clear bits i through j in N
    int allOnes = ~0; // all 1s
    
    // 1s before poistion j, then 0s, left = 1111000....
    int left = allOnes << (j+1);
    
    // 1s after position i, right = 00000111....
    int right = ((1<<i)-1);
    
    // All 1s, except for 0s between i and j. mask = 11110000000....111...
    int mask = left | right;
    
    // Clear bits j through i
    int Ncleared = N & mask; // Clear bits j through i
    int Mshifted = M << i; // Move m into correct position
    
    return Ncleared | Mshifted; // Use OR to merge them
    
}


int main() {
    int n = 1<<10, m = 21;
    int r = insert(n, m, 2, 6);
    printBit(n);
    printBit(m);
    printBit(r);
    getchar();
}



