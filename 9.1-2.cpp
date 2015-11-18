#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;
// Recursive method is called many times for the same values, which is uncessary,
// we can optimize this via dynamic programming

int countWaysDP(int n, int map[]) {
    if (n<0) return 0;
    if (n==0) return 1;
    if (map[n]!=0) return map[n];
    map[n] = countWaysDP(n-1, map)+countWaysDP(n-2, map)+countWaysDP(n-3, map);
    return map[n];
}

int main() {
    int m[10];
    cout<<countWaysDP(5, m)<<endl;
    getchar();
}







