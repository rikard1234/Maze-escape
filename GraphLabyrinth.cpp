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

    vector<Point2D> Coordinates;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            char buffor_x;
            file >> buffor_x;
            Point2D buffor_Coordinate;
            buffor_Coordinate.x = j;
            buffor_Coordinate.y = i;
            this->nodesCoordinates.push_back(buffor_Coordinate);
            this->nodesType.push_back(buffor_x);
        }
    }
    for(int i = 0; i < this->V; i++) {
        if(this->nodesCoordinates[i].x - 1 >= 0) this->adjacencyList[i].push_back(i - 1);
        if(this->nodesCoordinates[i].x + 1 < width) this->adjacencyList[i].push_back(i + 1);
        if(i + width < this->V && this->nodesCoordinates[i + width].x < this->V) this->adjacencyList[i].push_back(i + width);
        if(i - width >= 0 && this->nodesCoordinates[i - width].x >= 0) this->adjacencyList[i].push_back(i - width);
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