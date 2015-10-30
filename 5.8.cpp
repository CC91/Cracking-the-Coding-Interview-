#include <iostream>
#include <bitset>
using namespace std;

// Set full bytes between x1 and x2 then set residual start and end of the line via masks.
// Note that array starts from 0!

void drawLine(char* screen, int w, int x1, int x2, int y) {
    int startOffset = x1%8, firstFullByte = x1/8;
    int endOffset = x2%8, lastFullByte = x2/8;
    
    if (startOffset) firstFullByte++;
    if (endOffset) lastFullByte--; // because array is array[0]~array[x]
    
    for (int i=firstFullByte;i<=lastFullByte;i++) screen[w/8*y+i] = 0xFF;
    int startMask = 0xFF >> startOffset;
    int endMask = ~(0xFF >> (endOffset+1));
    
    if (startOffset) {
        int t = w/8*y+firstFullByte-1;
        screen[t] |= startMask;
    }
    
    if (endOffset) {
        int t = w/8*y+lastFullByte+1;
        screen[t] |= endMask;
    }
}

void printScreen(char* screen, int length, int w) {
    for (int i=0; i<length; i++) {
        if (i && i%(w/8)==0) cout<<endl;
        cout<<bitset<8>(screen[i]).to_string()<<' ';
    }
    cout<<endl;
}

int main() {
    const int len = 32; //screen size
    char screen[len]; // screen array
    drawLine(screen, 32, 3, 15, 2);
    printScreen(screen, 32, 32);
    getchar();
}

