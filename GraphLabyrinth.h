//
// Created by jakub on 02.07.2020.
//

#ifndef GRAPHS_GRAPHLABYRINTH_H
#define GRAPHS_GRAPHLABYRINTH_H
#include "Graph.h"
#include <string>
#include <iostream>

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
    private:
        vector<char> nodesType;
        vector<Point2D> nodesCoordinates;
        int S, F;
};


#endif //GRAPHS_GRAPHLABYRINTH_H
