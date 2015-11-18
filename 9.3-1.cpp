#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// brute force
int magicIdx(vector<int> array) {
    for (int i=0; i<array.size(); i++) {
        if (i==array[i]) return i;
    }
    return -1;
}




