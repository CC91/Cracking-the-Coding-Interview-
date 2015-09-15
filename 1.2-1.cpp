#include <iostream>
#include <string>
using namespace std;

void reverse(char* str) {
    char* head = str;
    char* tail = str +strlen(str)-1;
    while (head != tail) {
        char tmp = *tail;
        *(tail--) = *head;
        *(head++) = tmp;
//        head++;
//        tail--;
    }
}

int main() {
    char test_str[] = "hello world How r you";
    reverse(test_str);
    cout << test_str << endl;

}