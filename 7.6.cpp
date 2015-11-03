#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

// Define a hash map <lineX, numberOflineX> which can tolerate floating number difference.

struct Point {
    double x, y;
};

class Line {
public:
    double slope, intercept;
    double epsilon = 0.0001;
    bool infinite_slope;
public:
    Line(){};
    Line(Point p1, Point p2) {
        if (abs(p1.x-p2.x)>epsilon) {
            slope = (p1.y-p2.y)/(p1.x-p2.x);
            intercept = p1.y - slope*p1.x;
            infinite_slope=false;
        }
        else {
            infinite_slope = true;
            intercept =  p1.x; // x-intercept, since slope is infinite
        }
    }
    
    int hashMap() { // Re-define a hash map when the difference of two intercepts is < epsilon, they will be mapped to an int, which is the same in hash map
        int slp = (int)(slope*1000);
        int icp = (int)(intercept*1000);
        return slp*1000+icp;
    }
    
    void print() {
        cout<<"y= "<<slope<<"x + "<<intercept<<endl;
    }
};

Line findBestLine(Point *p, int Num) {
    Line bestLine;
    bool first = true;
    map<int, int> m;
    for (int i=0; i<Num; i++) {
        for (int j=i+1; j<Num; j++) {
            Line L(p[i], p[j]);
            if (m.find(L.hashMap()) == m.end()) {
                m[L.hashMap()] = 0;
            }
            m[L.hashMap()] += 1;
            
            if (first) {
                bestLine = L;
                first = false;
            }
            else if (m[L.hashMap()] > m[bestLine.hashMap()]) bestLine = L;
        }
    }
    return  bestLine;
}

int main() {
    srand((unsigned)time(0));
    int graphSize = 100;
    int num = 500;
    Point *p = new Point[num];
    for (int i=0; i<num; i++) {
        p[i].x = rand()/double(RAND_MAX)*graphSize;
        p[i].y = rand()/double(RAND_MAX)*graphSize;
    }
    Line L = findBestLine(p, num);
    L.print();
    getchar();
}





