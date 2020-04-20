//
// Created by Kuba on 03.04.2020.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Graph {
public:
    int V, E;
    void readFromFile();
    void print();
    vector<int> bfs(int n);
    Graph(string);
private:
    vector<int>* adjacencyList;
    int** weightMatrix;
};


#endif //GRAPHS_GRAPH_H
