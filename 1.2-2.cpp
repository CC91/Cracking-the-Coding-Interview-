#include <iostream>
#include <string>
using namespace std;

void reverse(char* str) {
    string s(str);
    for(std::string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
        cout << *rit;
}

int main() {
    char test_str[] = "hello world How r you";
    reverse(test_str);
    cout << test_str << endl;

}