#include <iostream>
#include <list>
using namespace std;
// BFS search the path
// Reference: http://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/


// a directed graph using adjacency list representation
class graph {
    int V; // # of vertices
    list<int> *adj; // pointer to anarray containing adjacency lists
public:
    graph (int V); // constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool search(int s, int d); // returns true if there is a path from s to d
};

graph::graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void graph::addEdge(int v, int w) {
    adj[v].push_back(w);// add w to v's list
}

bool graph::search(int s, int d) {
    if (s==d) return true; // base case
    bool *visited = new bool[V];
    for (int i=0; i<V; i++) visited[i]=false; // mark all the vertices not valid
    
    // create a queue for BFS
    list<int> queue;
    
    // mark current node as visited and equeue it
    visited[s] = true;
    queue.push_back(s);
    
    // get all adjacent vertices of a vertex
    list<int>::iterator i;
    
    while (!queue.empty()) {
        // dequeue a vertex from queue and print it
        s=queue.front();
        queue.pop_front();
        
        // get all adjacent vertices of the dequeued vertex s, if an adjacent has not been visited, then mark it visited
        for (i=adj[s].begin(); i != adj[s].end(); ++i) {
            if (*i==d) return true;
            if (!visited[*i]) {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}


int main() {
    graph t(4);
    t.addEdge(0, 1);
    t.addEdge(0, 2);
//    t.addEdge(1, 2);
    t.addEdge(2, 0);
    t.addEdge(2, 3);
    t.addEdge(3, 3);
    
    if(t.search(1, 3)) cout<<"Path from 1 to 3 exists!"<<endl;
    else cout<<"Path from 1 to 3 doesn't exist!"<<endl;
}