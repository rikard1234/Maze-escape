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
    void printPensja();
    Graph(string);

private:
    vector<int>* adjacencyList;
    int** pensjaMatrix;
};


#endif //GRAPHS_GRAPH_H
