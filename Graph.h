#pragma once

#include <map>
#include <iostream>
#include <list>
#include <set>

using namespace std;

template <class T>
class Graph {

private:
    map<T, set<T>> adj_list;

public:
    Graph();
    void addVertex(T val, set<T> edges);
    set<T> getNeighbours(T vertex);
};
