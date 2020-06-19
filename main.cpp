#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include <queue>
#include <stack>

using namespace std;

template <class T>
void bfs(T vertex, Graph<T>& graph) {
    // queue for bfs and set for checking if nodes have been visited
    queue<T> myQueue;
    set<T> visited;

    //enqueue the vertex
    myQueue.push(vertex);

    //while there are still nodes to be visited
    while (!myQueue.empty()) {

        //get the node to be searched next and add it to visited
        T curr = myQueue.front();
        myQueue.pop();
        visited.insert(curr);
        cout << "Visiting node:" << curr << endl;

        //add all the nodes neighbours to the queue
        for (T elem : graph.getNeighbours(curr)) {
            class set<T> ::iterator it = visited.find(elem);

            //if the neighbours of the current node have been visitted then dont add to queue
            if (it == visited.end()) {
                myQueue.push(elem);
            }
        }
    }
}

template <class T>
void dfs(T vertex, Graph<T>& graph) {
    stack<T> stack;
    set<T> visited;

    stack.push(vertex);

    while (!stack.empty()) {
        T curr = stack.top();
        stack.pop();
        visited.insert(curr);
        cout << "Visiting node:" << curr << endl;

        for (T elem : graph.getNeighbours(curr)) {
            class set<T> ::iterator it = visited.find(elem);

            if (it == visited.end()) {
                stack.push(elem);
            }
        }
        
    }
 
}


int main() {
    //initialize graph
    Graph<int> graph1;

    //create simple tree
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    set<int> connections1 = { 2, 3 };
    set<int> connections2 = { 4, 5 };
    set<int> connections3 = { 6, 7 };

    graph1.addVertex(1, connections1);
    graph1.addVertex(2, connections2);
    graph1.addVertex(3, connections3);

    // perfrom BFS
    cout << "Running Breadth First Search" << endl;
    bfs<int>(1, graph1);
    cout << endl;
    cout << "Running Breadth First Search" << endl;
    dfs<int>(1, graph1);
    cout << endl;

    Graph<string> graph2;
    set<string> connectionsS1 = { "Two", "Three" };
    set<string> connectionsS2 = { "Four", "Five" };
    set<string> connectionsS3 = { "Six", "Seven" };

    graph2.addVertex("One", connectionsS1);
    graph2.addVertex("Two", connectionsS2);
    graph2.addVertex("Three", connectionsS3);

    cout << "Running Breadth First Search" << endl;
    bfs<string>("One", graph2);
    cout << endl;

    cout << "Running Depth First Search" << endl;
    dfs<string>("One", graph2);
    cout << endl;

    return 0;
}