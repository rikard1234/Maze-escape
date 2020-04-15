//
// Created by Kuba on 03.04.2020.
//A{!tt
#include "Graph.h"

Graph::Graph(string path) {
        ifstream file;
        file.open(path);
        file >> this->V >> this->E;

        this->adjacencyList = new vector<int>[V];
        this->weightMatrix = new int*[V];

        for(int i = 0; i < V; ++i) weightMatrix[i] = new int[V];
        for(int i = 0; i < V; ++i)  {
            for(int j = 0; j < V; ++j) {
                weightMatrix[i][j] = 0;
           }
        }
        while(true) {
            int v, u, weight;
            file >> v >> u >> weight;
            this->weightMatrix[v][u] = weight;
            this->weightMatrix[u][v] = weight;
            this->adjacencyList[u].push_back(v);
            if(u != v) {
               this->adjacencyList[v].push_back(u);
            }
            if( file.eof() ) break;
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
      for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << this->weightMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

