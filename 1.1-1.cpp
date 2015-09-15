#include <iostream>
#include <string>
using namespace std;

bool isUnq(string str) {
    if (str.length() > 256) return false;
bool sg[256] = {false};
for (int i = 0; i < str.length(); i++)
{
    int idx = str.at(i);
    if (sg[idx]) return false;
    sg[idx]=true;
}
return true;
}

int main() {
    string test = "qaws12345qws";
    cout << isUnq(test) << endl;
}