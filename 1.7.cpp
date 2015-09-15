#include <iostream>
#include <string>
using namespace std;

void zeros(int m, int n, int **matrix)
{
    bool rowFlag[m];
    bool colFlag[n];
    memset(rowFlag, 0, sizeof(rowFlag)); // variable sized object need to be initialized like this
    memset(colFlag, 0, sizeof(colFlag));
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (matrix[i][j] == 0)
            {
                rowFlag[i] = true;
                colFlag[j] = true;
            }
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (rowFlag[i] || colFlag[j]) matrix[i][j] = 0;
}


int main() {
    int m = 3, n = 4;
    
    // initialize the matrix
    int **test;
    test = new int*[m];
    for (int i = 0; i < m; i++)
        test[i] = new int[n];
    
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            test[i][j] = rand()%10;
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    zeros(m, n, test);
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cout << test[i][j] << " ";
        cout << endl;
    }

}




