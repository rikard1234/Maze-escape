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
    char Labyrinth[height][width];
    vector<Point2D> Coordinates;

    this->adjacencyList = new vector<int>[V];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            file >>Labyrinth[i][j];
            Point2D buffor_Coordinate;
            buffor_Coordinate.x = j;
            buffor_Coordinate.y = i;
            this->nodesCoordinates.push_back(buffor_Coordinate);
            this->nodesType.push_back(Labyrinth[i][j]);
        }
    }
        for(int i = 0; i < V; i++) {
        if(this->nodesCoordinates[i].x == 0 && this->nodesCoordinates[i].y == 0) {
            this->adjacencyList[0].push_back(1);
            this->adjacencyList[0].push_back(width);
        }
        else if(this->nodesCoordinates[i].x == width * (height - 1)) {
            this->adjacencyList[i].push_back(i + 1);
            this->adjacencyList[i].push_back(i - width);
        }
        else if(this->nodesCoordinates[i].x == width - 1 && this->nodesCoordinates[i].y == 0) {
            this->adjacencyList[i].push_back(i - 1);
            this->adjacencyList[i].push_back(i + width);
        }
        else if(this->nodesCoordinates[i].x == width - 1 && this->nodesCoordinates[i].y == height - 1) {
            this->adjacencyList[i].push_back(i - 1);
            this->adjacencyList[i].push_back(i - width);
        }

        else if(this->nodesCoordinates[i].x == 0) {
            this->adjacencyList[i].push_back(i + 1);
            this->adjacencyList[i].push_back(i + width);
        }
        else if(this->nodesCoordinates[i].y == 0) {
            this->adjacencyList[i].push_back(i + width);
            this->adjacencyList[i].push_back(i - 1);
            this->adjacencyList[i].push_back(i + 1);
        }
        else if(this->nodesCoordinates[i].x == width - 1) {
            this->adjacencyList[i].push_back(i - 1);
            this->adjacencyList[i].push_back(i + width);
            this->adjacencyList[i].push_back(i - width);
        }
        else if(this->nodesCoordinates[i].y == height - 1) {
            this->adjacencyList[i].push_back(i - width);
            this->adjacencyList[i].push_back(i - 1);
            this->adjacencyList[i].push_back(i + 1);
        }
        else {
            this->adjacencyList[i].push_back(i - width);
            this->adjacencyList[i].push_back(i + width);
            this->adjacencyList[i].push_back(i - 1);
            this->adjacencyList[i].push_back(i + 1);
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