#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2)
{
    if (s1.find(s2) != std::string::npos) return true;
    else return false;
}


bool isRotation(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        string msk = s1+s1;
        return (isSubstring(msk, s2));
    }
    else return false;
}

int main()
{
    string s1 = "helloworld";
    string s2 = "orldhellow";
    cout << isRotation(s1, s2) << endl;
}




