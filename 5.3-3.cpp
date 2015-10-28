#include <iostream>
#include <string>
using namespace std;
// Arithmetic approach
// Largest: flip the rightmost non-trailing zero to one, adjust # of 1s and 0s to the right of the flipped bit.
// Smallest: flip the rightmost non-trailing one to zero.

int ones(int n) { // count # of 1s in n
    int count = 0;
    for (int i=0; i<32; i++) {
        if (n & 1) count += 1;
        n >>= 1; // Attention!
    }
    return count;
}

int largest(int x) {
    // count # of 1s: c1 and # of 0s: c0 to the right of p
    int c0 = 0;
    int c1 = 0;
    int tmp = x;
    
    while (tmp && (tmp&1) == 0 ) { // count # of 0s first
        c0 += 1;
        tmp >>= 1;
    }
    
    while ((tmp&1)==1) { // then check # of 1s
        c1 += 1;
        tmp >>= 1;
    }
        
    // error check:
    if (c0+c1 == 31 || c0+c1 == 0) return -1; // if x is like 111100000...00, then there is no bigger number with same # of 1s

    return x + (1<<c0) + (1<<(c1-1)) -1;
}

int smallest(int y) {
    // count non-trailing ones first
    int c1 = 0;
    int c0 = 0;
    int tmp = y;
    while ((tmp&1)==1) {
        c1 += 1;
        tmp >>= 1;
    }
    
    // error check: if y is like 011111, there is no smallest number of y with same 0s
    if (tmp == 0) return -1;
    
    while ((tmp&1)==0) {
        c0 += 1;
        tmp >>=1;
    }
    
    return y-(1<<c1)-(1<<(c0-1))+1;
}

int main() {
    cout<<"smallest: "<<smallest(50)<<endl;
    cout<<"largest: "<<largest(50)<<endl;
    getchar();
}

