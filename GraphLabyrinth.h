//
// Created by jakub on 02.07.2020.
//

#ifndef GRAPHS_GRAPHLABYRINTH_H
#define GRAPHS_GRAPHLABYRINTH_H
#include "Graph.h"
#include "queue"
#include <string>
#include <iostream>
#include <math.h>
struct Point2D {
    int x;
    int y;
};

class GraphLabyrinth : Graph {
    public:
        GraphLabyrinth(string);
        void displayAdjacencyList();
        vector<int> bfs();
        vector<int> dfs();
        vector<int> A();
    private:
        int* costs;
        vector<char> nodesType;
        vector<Point2D> nodesCoordinates;
        int S, F;
};


#endif //GRAPHS_GRAPHLABYRINTH_H
