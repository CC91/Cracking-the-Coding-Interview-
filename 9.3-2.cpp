#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// Since the array is sorted, we can think about the binary search method
// 2 pointers

int magicIdx(vector<int> array) {
    int n = array.size();
    int left = 0, right = n-1;
    while (left<=right) {
        int mid = (left+right)>>1;
        if (array[mid]<mid) left = mid+1;
        else if (array[mid]>mid) right = mid-1;
        else return mid;
    }
    return -1;
}





