#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

// Top down: the last move might have been a single step hop from step n-1,
// a double step hop from step n-2, or a triple step hop from n-3. The totall
// number of ways of reaching the last step is therefore the sum of the number
// of ways of reaching each of the last three steps.

int countWays(int n) {
    if (n<1) return 0;
    else return 1+countWays(n-1)+countWays(n-2)+countWays(n-3);
}

int main() {
    cout<<countWays(3)<<endl;
    getchar();
}

// Like Fibonaci problem, the runtime is exponential O(3^n)






