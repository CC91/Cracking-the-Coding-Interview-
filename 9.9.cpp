#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// Each row and each column must be used exactly once.
int GRID = 8;

bool checkValid(vector<int> columns, int row1, int column1) {
    for (int row2=0; row2<row1; row2++) {
        int column2 = columns[row2];
        
        if (column1==column2) return false; //Check if (r2, c2) invalidates (r1, c1) as a queen spot.
        
        // If the distance between the columns equals the distance between the rows, they are in the same diagonal.
        int columnDistance = abs(column2-column1);
        int rowDistance = row1-row2;
        if (columnDistance==rowDistance) return false;
    }
    return true;
}

void placeQueens(int row, vector<int> &columns, vector<vector<int>> &res) {
    if (row==GRID) res.push_back(columns); // Found valid placement
    else {
        for (int col=0; col<GRID; col++) {
            if (checkValid(columns, row, col)) {
                columns[row] = col; // Place queen
                placeQueens(row+1, columns, res);
            }
        }
    }
}


