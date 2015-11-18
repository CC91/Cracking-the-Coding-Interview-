#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
// 2^n subsets, so O(2^n) time/space complexity
// Recursion method: base case n=0, just an empty set: {}
// Case n=1: {}, {a1}
// Case n=2: {}, {a1}, {a2}, {a1, a2}
// Case n=3: {}, {a1}, {a2}, {a3}, {a1, a2}, {a1, a3}, {a2, a3}, {a1, a2, a3}

vector<vector<int>> getvecSubsets(vector<int> &set) {
    vector<vector<int>> res;
    vector<int> tmp;
    res.push_back(tmp);
    for (int i=0; i<set.size(); i++) {
        for (int j=0; j<res.size(); j++) {
            tmp = res[j];
            tmp.push_back(set[i]);
            res.push_back(tmp);
        }
    }
    return res;
}






