#include <iostream>
#include <string>
using namespace std;
// To rotate the image, we can first transpose the matrix, then flip the transposed matrix (use a piece of paper to see)
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void rotateImg(int n, int m[][5])
{
    for (int i = 0; i < n; ++i) // transpose the matrix
        for (int j = i+1; j < n; ++j)
            swap(m[i][j], m[j][i]);
    for (int i = 0; i < n/2; ++i) // flip the transposed matrix
        for (int j = 0; j < n; ++j)
            swap(m[i][j], m[n-i-1][j]);
}

int main() {
    int n = 5;
    int test[n][5];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                test[i][j] = rand()%10;
                cout << test[i][j] << " ";
            }
            cout << endl;
        }
    
    cout << endl;
    cout << "rotated matrix is: " <<endl;
    rotateImg(n, test);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
}



