#include <iostream>
#include <string>
//only lowercase letters can be applied with this method
using namespace std;

bool isUnq(string str) {
	int mask = 0;
for (int i = 0; i < str.length(); i++)
{
    int n = str.at(i);
    int val = n-'a'; // idx: 0-7, shift:0-31
    if (mask & (1<<val)) return false;
    mask |= (1<<val);
}
return true;
}

int main() {
    string test = "12ewqrqa3456";
    cout << isUnq(test) << endl;
}