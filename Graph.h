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
    bool* visited;
    void readFromFile();
    void print();
    void bfs(int n);
    vector<int> pre_bfs(int n);
    Graph(string);
private:
    vector<int>* adjacencyList;
    int** weightMatrix;
    vector<int> order;
};


#endif //GRAPHS_GRAPH_H
