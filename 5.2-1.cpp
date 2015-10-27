#include <iostream>
#include <string>

using namespace std;

string printBinary(double x) {
    if (x>=1 || x<=0) return "ERROR";
    
    string binary;
    binary += ".";
    while (x>0) {
        // setting length limit: 32
        if (binary.length() >= 32) return "Error";
        
        double r = x*2;
        if (r>=1) {
            binary += "1";
            x = r-1;
        }
        else {
            binary += "0";
            x = r;
        }
    }
    return binary;
}


int main() {
    string r = printBinary(0.625);
    cout<<r<<endl;
    getchar();
}



