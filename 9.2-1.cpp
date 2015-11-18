#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

// dp: dp[i][j] = dp[i-1][j]+dp[i][j-1]
int getPaths(int m, int n) {
    int res[m][n];
    
    // initialization
    for (int i=0; i<m; i++) res[i][0]=1;
    for (int i=0; i<n; i++) res[0][i]=1;
    
    // dp
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++)
            res[i][j] = res[i-1][j]+res[i][j-1];
    }
    return res[m-1][n-1];
}
int main() {
    cout<<getPaths(10, 10)<<endl;
    getchar();
}



