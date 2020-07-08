//
// Created by jakub on 02.07.2020.
//

#include "GraphLabyrinth.h"

GraphLabyrinth::GraphLabyrinth(string path) {
    ifstream file;
    file.open(path);

    int width;
    int height;
    file >> width >> height;
    this->V = width * height;
    this->adjacencyList = new vector<int>[V];

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            char bufforX;
            file >> bufforX;
            Point2D bufforCoordinate;
            bufforCoordinate.x = j;
            bufforCoordinate.y = i;
            this->nodesCoordinates.push_back(bufforCoordinate);
            this->nodesType.push_back(bufforX);
        }
    }
    for(int i = 0; i < this->V; i++) {
        if(this->nodesType[i] == 'S') this->S = i;
        if(this->nodesType[i] == 'F') this->F = i;
        if(this->nodesType[i] != 'O') {
            if (i - 1 >= 0 && this->nodesCoordinates[i].x - 1 >= 0 && this->nodesType[i - 1] != 'O') this->adjacencyList[i].push_back(i - 1);
            if (i + 1 < this->V && this->nodesCoordinates[i].x + 1 < width && this->nodesType[i + 1] != 'O') this->adjacencyList[i].push_back(i + 1);
            if (i + width < this->V && this->nodesCoordinates[i + width].x < this->V && this->nodesType[i + width] != 'O') this->adjacencyList[i].push_back(i + width);
            if (i - width >= 0 && this->nodesCoordinates[i - width].x >= 0 && this->nodesType[i - width] != 'O') this->adjacencyList[i].push_back(i - width);
        }
    }
}

void GraphLabyrinth::displayAdjacencyList() {
    for(int i = 0; i < V; i++) {
        cout << "NODE " << i << ": ";
        for(int j = 0; j < this->adjacencyList[i].size(); j++) {
            cout << this->adjacencyList[i].at(j) << " ";
        }
        cout << endl;
    }
}

vector<int> GraphLabyrinth::bfs() {
    return Graph::bfs(this->S, this->F);
}

vector<int> GraphLabyrinth::dfs() {
    return Graph::dfs(this->S, this->F);
}