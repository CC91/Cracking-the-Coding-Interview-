#include <iostream>
#include <string>
using namespace std;
// Basic implementation 

// fetch jth bit of a[i]
int fetch(int a[], int i, int j) {
    return (a[i]>>j)&1;
}

// get an element in a like a[i]
int get(int a[], int i) {
    int v = 0;
    for (int j=31; j>=0; j--)
        v = (v<<1) | fetch(a, i, j);
    return v;
}

int findMissing(int a[], int n) {
    bool *flag = new bool[n+1]; // pointer points to the array
    memset(flag, false, (n+1)*sizeof(bool));
    for (int i=0; i<n; i++) flag[get(a, i)] = true;
    for (int i=0; i<(n+1); i++) {
        if (!flag[i]) return i;
    }
    delete[] flag;
    return NULL;
}

int main() {
    int a[] = {0,1,2,3,4,5,6,8,9,10};
    cout<< findMissing(a, 10);
    
    getchar();
}

