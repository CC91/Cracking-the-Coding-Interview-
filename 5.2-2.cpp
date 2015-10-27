#include <iostream>
#include <string>

using namespace std;
// Alternative, rather than *2 and compare to 1, we can compare it to 0.5 then 0.25 and so on.
string printBinary(double x) {
    if (x>=1 || x<=0) return "ERROR";
    
    string binary;
    binary += ".";
    double frac = 0.5;
    while (x>0) {
        // setting length limit: 32
        if (binary.length() >= 32) return "Error";
        
        if (x>=frac) {           // decimal: 1*(1/2^1)+1*(1/2^2)+1*(1/2^3)....
            binary += "1";
            x -=frac;
        }
        else binary += "0";
        frac /= 2;
    }
    return binary;
}


int main() {
    string r = printBinary(0.625);
    cout<<r<<endl;
    getchar();
}



