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
#include <utility>
#include <set>
struct Point2D {
    int x;
    int y;
};
struct myComparator {
    constexpr bool operator()(
            pair<int, float> const& a,
            pair<int, float> const& b)
    const noexcept
    {
        return a.second > b.second;
    }
};
class GraphLabyrinth : Graph {
    public:
        GraphLabyrinth(string);
        void displayAdjacencyList();
        vector<int> bfs();
        vector<int> dfs();
        vector<pair<int,float>> a();
    private:
        int* costs;
        int* currentCosts;
        float* priority;
        vector<char> nodesType;
        vector<Point2D> nodesCoordinates;
        int S, F;
};


#endif //GRAPHS_GRAPHLABYRINTH_H
