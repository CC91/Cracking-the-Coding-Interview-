#include <iostream>
#include <string>
using namespace std;

void replaceSpace(string str) {
    size_t counter = std::count(str.begin(), str.end(),' ');
    if (counter) {
        while (true) {
            size_t pos = str.find(" ");
            if (pos == str.npos) break; //npos means not found which is -1
            str[pos] = '%';
            str.insert(++pos, "20");
        }
    }
    cout << str <<endl;
}


int main () {
    string test = "hello how are you doing? ";
    replaceSpace(test);
    //cout << test << endl;
}

