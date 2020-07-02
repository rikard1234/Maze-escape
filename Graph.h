//
// Created by Kuba on 03.04.2020.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
class Graph {
public:
    void readFromFile();
    void print();
    vector<int> bfs(int n);
    vector<int> dfs(int n);
    void init(int, bool*, deque<int>&);
    void visitNeighbors(int, bool*, deque<int>&);
    void checkForUnvisitedNode(bool*, deque<int>&);
    Graph(string);
private:
    int V, E;
    vector<int>* adjacencyList;
    int** weightMatrix;
};


#endif //GRAPHS_GRAPH_H
