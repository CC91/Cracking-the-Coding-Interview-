#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;
// The line that cuts 2 squares in half must connect two middles. We can compute the slope using 2 middles: s=(y1-y2)/(x1-x2).
// Assume the square points are diagonal points defined: (left, top), (right, bottom), and e(edge length of the square)

class Point {
public:
    double x1, y1;
    Point(double x, double y): x1(x), y1(y) {};
};

class Line {
public:
    Point begin1, end1;
    Line(Point begin, Point end):begin1(begin), end1(end) {};
};

// Connect two middles of squares
class Square {
public:
    double left1, top1, right1, bottom1, e1;
    Square(double left, double top, double right, double bottom, double e):left1(left), top1(top), right1(right), bottom1(bottom), e1(e) {};
    Point middle() {
        return Point((left1+right1)*0.5, (top1+bottom1)*0.5);
    }

// Extend middle connected line to an outer edge of a square
    Point extend(Point mid1, Point mid2, double e) {
        // Find what direction the line mid2->mid1 goes.
        double xdir = mid1.x1<mid2.x1?-1:1;
        double ydir = mid1.y1<mid2.y1?-1:1;
    
        // if mid1 and mid2 have the same x value, then slope is an exception.
        if (mid1.x1 == mid2.x1) return Point(mid1.x1, mid1.y1+ydir*e*0.5);
    
        double slope = (mid1.y1-mid2.y1)/(mid1.x1-mid2.x1);
        double x=0, y=0;
        if (fabs(slope)==1) {
            x = mid1.x1+xdir*e*0.5;
            y = mid1.y1+ydir*e*0.5;
        }
        else if (fabs(slope)<1) {  //shallow slope
            x = mid1.x1+xdir*e*0.5;
            y = mid1.y1+slope*(x-mid1.x1);
        }
        else { // steep slope
            y = mid1.y1+ydir*e*0.5;
            x = (y-mid1.y1)/ slope+mid1.x1;
        }
        return Point(x, y);
    }

// Calculate a line between each middle would collide with the edges of the squares
    Line cut(Square other) {
        Point p1=extend(middle(), other.middle(), e1);
        Point p2=extend(middle(), other.middle(), -1*e1);
        Point p3=extend(other.middle(), middle(), other.e1);
        Point p4=extend(other.middle(), middle(), -1*other.e1);
        
        // Of above points, find start and end of lines. Start is farthest left and end is farthest right
        Point start = p1;
        Point end = p1;
        vector<Point> points = {p2,p3,p4};
        for(int i=0; i<points.size(); i++) {
            if (points[i].x1<start.x1 || (points[i].x1 == start.x1 && points[i].y1 < start.y1)) start=points[i];
            else if (points[i].x1 > end.x1 || (points[i].x1 == end.x1 && points[i].y1 > end.y1)) end=points[i];
        }
    return Line(start, end);
    }
};

// OMG......







