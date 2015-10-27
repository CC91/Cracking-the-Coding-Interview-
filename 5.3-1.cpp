#include <iostream>
#include <string>
using namespace std;

// The Brute Force Approach: count # of 1s in n, then increment/decrement until you find a number with the same # of 1s.

int ones(int n) { // count # of 1s in n
    int count = 0;
    for (int i=0; i<32; i++) {
        if (n & 1) count += 1;
        n >>= 1; // Attention!
    }
    return count;
}

int largest(int x) {
    int max = ~(1<<31);
    int p = ones(x);
    if (p==0) return 0;
    for (++x; ones(x)!=p && x<max; ++x);
    if (ones(x)==p) return x;
    return 0;
}

int smallest(int y) {
    int min = (1<<31);
    int p = ones(y);
    if (p==0) return 0;
    for (--y; ones(y)!=p && y>min; --y);
    if (ones(y)==p) return y;
    return 0;
}

int main() {
    cout<<"smallest: "<<smallest(50)<<endl;
    cout<<"largest: "<<largest(50)<<endl;
    getchar();
}

