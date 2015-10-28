#include <iostream>
#include <string>
using namespace std;
// A XOR B, count the number of bits 1.

int bitSwapRequired(int a, int b) {
    int c = 0;
    for (int p = a^b; p!=0; p>>=1) c += p&1;
    return c;
}

int main() {
    cout<< bitSwapRequired(5, 10);
    
    getchar();
}

