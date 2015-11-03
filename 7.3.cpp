#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Line {
    double epsilon = 0.000001;
    double slope;
    double yintercept;
    
    Line(double s, double y) {

        slope = s;
        yintercept = y;
    }
    
    bool intersect(Line line2) {
        return abs(slope-line2.slope)>epsilon || abs(yintercept-line2.yintercept)<epsilon;
    }
};

// Don't assume that the slope and yintercept are integers.
// Understand limitations of floating point representations, never check for equality with ==. Instead, check if the difference is less than an epsilon value.