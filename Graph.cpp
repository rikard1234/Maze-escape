//
// Created by Kuba on 03.04.2020.
//A{!tt
#include "Graph.h"

Graph::Graph(string path) {
        ifstream file;
        file.open(path);
        file >> this->V >> this->E;

        this->adjacencyList = new vector<int>[V];
        this->pensjaMatrix = new int*[V];

        for(int i = 0; i < V; ++i) pensjaMatrix[i] = new int[V];
        for(int i = 0; i < V; ++i)  {
            for(int j = 0; j < V; ++j) {
                pensjaMatrix[i][j] = 0;
           }
        }
        while(true) {
            int v, u, wage;
            file >> v >> u >> wage;
            if( file.eof() ) break;
            this->pensjaMatrix[v][u] = wage;
            if(u != v) {
                this->adjacencyList[u].push_back(v);
                this->adjacencyList[v].push_back(u);
            }
            else {
                this->adjacencyList[u].push_back(v);
            }
        }
    file.close();
}

void Graph::print() {
    for (int v = 0; v < V; v++) {
        cout << "Vertex :" << v << " -> ";
        for (int i = 0; i < adjacencyList[v].size(); i++) {
            int x = adjacencyList[v].at(i);
            cout << x << " ";
        }
        cout << endl;
    }
}

void Graph::printPensja() {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << this->pensjaMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
