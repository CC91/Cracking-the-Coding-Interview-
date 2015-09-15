#include <iostream>
#include <string>
using namespace std;

void rotateImg(int n, int m[][5])
{
    int tmp[n/2][n];
    int final[n][n]; //the result matrix, avoid overwritng on the original matrix
    final[n/2][n/2] = m[n/2][n/2]; // the centeral element won't be rotated
    
    for (int top = 0; top < n/2; ++top)
    {
        for (int i = 0; i < n; ++i)
        {
            // save top
            tmp[top][i] = m[top][i];
            
            // left to top
            final[top][i] = m[n-i-1][top];
            
            // bottom to left ///
            final[i][top] = m[n-top-1][i];
            
            // right to bottom
            final[n-top-1][i] = m[n-i-1][n-top-1];
            
            // top to right
            final[i][n-top-1] = tmp[top][i];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << final[i][j] << " ";
        cout<<endl;
    }
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
    cout << endl;
    cout << "rotated matrix is: " <<endl;
    cout << endl;
    rotateImg(n, test);
}



