#include <iostream>
#include <string>
using namespace std;

bool isUnq(string s) {
    if (s.length()>256) return false;
    sort(s.begin(), s.end());
    for (int i=1; i<s.length(); i++) {
        if (s[i]==s[i-1]) return false;
    }
    return true;
}

int main() {
    string s={"ACDUIEWBSFA"};
    cout<<isUnq(s);
    getchar();
}