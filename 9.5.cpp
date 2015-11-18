#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// Base case: n=1, S=a1
// Case: n=2, S=a1a2, a2a1
// Case: n=3, S=a1a2a3, a3a2a1, a1a3a2, a2a3a1, a3a1a2, a2a1a3

vector<string> getPerms(string str) {
    vector<string> res;
    if (str.empty()) { // base case
        res.push_back("");
        return res;
    }
    
    string remainder = str.substr(0, 1);
    res = getPerms(remainder.substr(1));
    for (int i=0; i<str.size(); i++) {
        string tmp = res[i];
        for (int j=0; j<=tmp.size(); j++) {
            string cur = tmp;
            cur.insert(j, remainder);
            res.push_back(cur);
        }
    }
    return  res;
}



