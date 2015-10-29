#include <iostream>
#include <string>
using namespace std;
// Mask all odd bits with 10101010, all even bits with 01010101.
// It takes 5 instructions: number & mask_odd then shift right, number & mask_even then shift left, at last or (merge).

int swapOddEven(int x) {
    return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1); // 0xaaaaaaaa is 32 bits, same as 0x55555555
    // shift operation (>>, <<) has higher priority than and operation (&), use brackets!
}

int main() {
    cout<< swapOddEven(42);
    
    getchar();
}

