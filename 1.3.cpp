#include <iostream>
#include <string>
using namespace std;

bool ifpermutation(string s1, string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    if (s1.compare(s2)){
        cout << "s1 is not permutation of s2." << endl;
        return 0;
        }
    else {
        cout << "s1 is permutation of s2." << endl;
        return 1;
    }
}

int main() {x
    string s1("hello hi! memeda");
    string s2("hi hello!");
    ifpermutation(s1, s2);
}