#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// use 2 queues for cats and dogs respectively

enum Animal {Cat, Dog};

class Shelter {
private:
    queue<int> dog;
    queue<int> cat;
public:
    void enQ(Animal id);
    int deQd(); //dequeue dog
    int deQc(); //dequeue cat
    int deQa(); //dequeue any
};

void Shelter::enQ(Animal id) {
    static int counter=0;
    if (id==Cat) cat.push(++counter);
    else dog.push(++counter);
}

int Shelter::deQd() {
    int val;
    if (!dog.empty()) {
        val=dog.front();
        cout<<"dequeue dog: "<<val<<endl;
        dog.pop();
    }
    return val;
}

int Shelter::deQc() {
    int val;
    if (!cat.empty()) {
        val=cat.front();
        cout<<"dequeue cat: "<<val<<endl;
        cat.pop();
    }
    return val;
}

int Shelter::deQa() {
    if (dog.empty()) return deQc();
    if (cat.empty()) return deQd();
    if (cat.front()<dog.front()) return deQc();
    else return deQd();
}

int main() {
    Shelter t;
    t.enQ(Cat);
    t.enQ(Cat);
    t.enQ(Cat);
    t.enQ(Dog);
    t.enQ(Cat);
    t.enQ(Cat);
    t.enQ(Dog);
    
    t.deQa();
    t.deQc();
    t.deQd();
}