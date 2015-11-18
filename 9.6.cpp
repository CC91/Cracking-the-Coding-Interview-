#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<string> &res, string item, int left, int right) {
    if (left>right) return;
    
    if (left==0 && right ==0) {
        res.push_back(item);
        return;
    }
    if (left>0) dfs(res, item+'(', left-1, right);
    if (right>0) dfs(res, item+')', left, right-1);
}



vector<string> generateParen(int n) {
    vector<string> res;
    string item = "";
    if (n<=0) return res;
    dfs(res, item, n, n);
    return res;
}



