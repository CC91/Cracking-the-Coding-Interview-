#include <iostream>
#include <stdlib.h>

using namespace std;

// flip a number to positive or negative
int flip(int a) {
    int res = 0;
    int tmp = a<0?1:-1;
    while (a!=0) {
        a += tmp;
        res += tmp;
    }
    return res;
}


// subtraction
int sub(int x, int y) {
    return x+flip(y);
}


// get abs value
int abs(int a) {
    if (a<0) return flip(a);
    else return a;
}


// multiplication, need to handle negative multiplier
int mul(int x, int y) {
    int sum = 0;
    for (int i=0; i<abs(y); i++)
        sum += x;
    return sum;
}


// division, z=x/y, x=yz, so find z where x=yz by adding y repeatedly until we reach x, the number of times we add will equal to z.
int divid(int x, int y) {
    int x1=abs(x);
    int y1=abs(y);
    
    int res = 0;
    
    int i = 0;
    while (res+y1 <= x1) {
        res += y1;
        i++;
    }
    if ((x<0 && y<0)||(x>0 && y>0)) return i;
        else return flip(i);
}


int main() {
    int x = -12, y = 2;
    cout<<flip(y)<<endl;
    cout<<sub(x, y)<<endl;
    cout<<abs(x)<<endl;
    cout<<mul(x, y)<<endl;
    cout<<divid(x, y)<<endl;
}

// Clean your code! Like using flip will be easier!
// Don't assume that the numbers are all positive or that x is bigger than y.
