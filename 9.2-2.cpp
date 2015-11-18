#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

// dp: dp[j] = dp[j]+dp[j-1]
int getPaths(int m, int n) {
    int res[n];
    
    // initialization
    for (int i=0; i<n; i++) res[i]=1;
    
    // dp
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++)
            res[j] += +res[j-1];
    }
    return res[n-1];
}
int main() {
    cout<<getPaths(10, 10)<<endl;
    getchar();
}



