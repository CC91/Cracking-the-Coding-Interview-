#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
// backtracking
void findSubSets(vector<int> &set, int start, vector<int> &tmp, vector<vector<int>> &res) {
    for (int i=start; i<set.size(); i++) {
        tmp.push_back(set[i]);
        res.push_back(tmp); // before go to next recursive call, push back the current subset
        findSubSets(set, i+1, tmp, res);
        tmp.pop_back();
    }
}

vector<vector<int>> getvecSubsets(vector<int> &set) {
    vector<vector<int>> res;
    vector<int> tmp;
    res.push_back(tmp);
    findSubSets(set, 0, tmp, res);
    return res;
}






