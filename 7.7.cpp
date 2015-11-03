#include <iostream>
#include <queue>
using namespace std;
// 1) Initialize the res =1 and 3 queues, q3, q5, q7.
// 2) Push 1*3, 1*5, 1*7 into 3 queues respectively.
// 3) Find the minimum x among the heads of 3 queues, and res = x.
// 4) If x is in q3, remove it from q3 and push 3*x, 5*x, 7*x into q3, q5, q7 respectively.
// 5) If x is in q5, remove it from q5 and push 5*x, 7*x into q5 and q7 respectively.
// 6) If s is in q7, remove it from q7 and push 7*x into q7.
// 7) Repeat 3)-6) to find the kth number.


int minF(int x, int y) {
    return x<y?x:y;
}

int minF(int x, int y, int z) {
    return minF(minF(x, y), z);
}

int getNum(int k) {
    int res = 1, count=1;
    queue<int> q3, q5, q7;
    q3.push(3);
    q5.push(5);
    q7.push(7);
    
    for (;count<k;count++) {
        int f3 = q3.front();
        int f5 = q5.front();
        int f7 = q7.front();
        res = minF(f3, f5, f7);
        
        if (res == f7) q7.pop();
        
        else {
            if (res == f5) {
              q5.pop();
            }
            
            else {
                if (res == f3) {
                    q3.pop();
                    q3.push(3*res);
                }
            }
            q5.push(5*res);
        }
        q7.push(7*res);
    }
    return  res;
}


int main() {
    for (int i=1; i<20; i++) {
        cout<<getNum(i)<<endl;
    }
    getchar();
}




