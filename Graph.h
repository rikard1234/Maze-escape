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
    const int V, E;
    void ReadFromFile();
    void Print();
    void PrintWages();
    Graph(int V, int E);

private:
    vector<int>* adjacencyList;
    int** wageMatrix;
};


#endif //GRAPHS_GRAPH_H
