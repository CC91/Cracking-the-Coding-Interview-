#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// Since the array is sorted, we can think about the binary search method
// recursion

int magicIdx(vector<int> &array, int start, int end) {
    int n = array.size();
    if (start>end || start<0 || end >=n) return -1;
    int mid = (start+end)/2;
    if (array[mid]==mid) return mid;
    else if (array[mid]>mid) return magicIdx(array, start, mid-1);
    else return magicIdx(array, mid+1, end);
}






