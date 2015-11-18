#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

enum Color{Black, White, Red, Yellow, Green};

bool paintFill(vector<vector<Color>> &screen, int x, int y, Color oldColor, Color newColor) {
    if (x<0 || x>=screen.size() || y<0 || y>=screen[0].size()) return false;
    
    if (screen[x][y]==oldColor) {
        screen[x][y]=newColor;
        paintFill(screen, x-1, y, oldColor, newColor);
        paintFill(screen, x+1, y, oldColor, newColor);
        paintFill(screen, x, y-1, oldColor, newColor);
        paintFill(screen, x, y+1, oldColor, newColor);
    }
    return true;
}

bool paintFill(vector<vector<Color>> &screen, int x, int y, Color newColor) {
    if (screen[x][y]==newColor) return false;
    return paintFill(screen, x, y, screen[x][y], newColor);
}



