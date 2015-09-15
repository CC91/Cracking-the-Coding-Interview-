#include <iostream>
#include <string>
using namespace std;

void strComp(string str) {
    int counter = 1;
    string newStr = "";
    char pre = str.at(0);
    for(int i = 1; i < str.length(); i++)
    {
        if (str[i] == pre) counter++;
        else {
            newStr += pre + to_string(counter);
            pre = str.at(i);
            counter = 1;
        }
    }
    cout << newStr + pre + to_string(counter)<< endl;
    //cout << "compressed str len is"<<newStr.length()<<endl;
}



int main() {
    string test = "aabbccffgghhrreesedxzrrddd";
//    cout<<"original string len is" << test.length()<< endl;
    strComp(test);
}