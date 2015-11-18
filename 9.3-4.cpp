#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// follow up: the elements are not distinct

int magicIdx(vector<int> &array, int start, int end) {
    int n = array.size();
    if (start>end || start<0 || end >=n) return -1;
    int mid = (start+end)/2;
    int midValue = array[mid];
    
    if (midValue==mid) return mid;
    
    // search left
    int left = min(mid-1, midValue);
    int leftIdx = magicIdx(array, start, left);
    if (leftIdx>=0) return leftIdx;
    
    // search right
    int right = min(mid+1, midValue);
    int rightIdx = magicIdx(array, right, end);
    
    return rightIdx; // be brief!
}


int main() {
    vector<int> t{-10,-5,2,2,2,3,4,7,9,12,13};
    cout<<magicIdx(t, 0, 7)<<endl;
    getchar();
}




