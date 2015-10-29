#include <iostream>
#include <vector>
//#include <math.h>
using namespace std;
// Array stores 0-n.
// Basic idea: sum up all elements in the array and compare with n*(n+1)/2, the difference will be the missing number.
// However, the runtime of it is n*length(n), and length(n)= log2(n) (n = 2^l, l = log2(n)), so the runtime is actually
// O(n*log(n)).

// 1) The missing number makes the least significant bit of the array imbalance, the pattern before removing should be
// 010101010...., after might be 010101011....
// 2) If n is odd (n%2 == 1), there should be same # of 1s and 0s, if n is even (n%2 == 0), there should be one more 0 than 1s.
// 3) Therefore, # of 0s >= # of 1s.

// fetch jth bit of a number
int fetch(int a, int j) {
    return (a>>j)&1;
}

int findMissing(vector<int> array, int col) {
    
    if (array.empty()) return 0; // base case
    
    vector<int> oneBits, zeroBits;
    
    for (auto &a : array) {
        if (fetch(a, col) == 0) zeroBits.push_back(a);
        else oneBits.push_back(a);
    }
    
    if (zeroBits.size() <= oneBits.size()) {
        int v = findMissing(zeroBits, col+1);
        return (v<<1) | 0; // insert 0 or 1 depending on # of 1s and 0s of LSB
    }
    else {
        int v = findMissing(oneBits, col+1);
        return (v<<1) | 1;
    }
}

int findMissing(vector<int> array) {
    return findMissing(array, 0);
}

int main() {
    vector<int> a = {0,1,2,3,4,5,6,8,9,10};
    cout<< findMissing(a);
    getchar();
}

