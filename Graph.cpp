//
// Created by Kuba on 03.04.2020.
//A{!tt
#include "Graph.h"

Graph::Graph(int V, int E) : V(V), E(E) {
        this->adjacencyList = new vector<int>[V];
        this->wageMatrix = new int*[V];

        for(int i = 0; i < V; ++i) wageMatrix[i] = new int[V];
        for(int i = 0; i < V; ++i)  {
            for(int j = 0; j < V; ++j) {
                wageMatrix[i][j] = 0;
           }
        }
}

void Graph::ReadFromFile() {
        ifstream file;
        int integer = 3;
        file.open("dane.txt");

        for (int i = 0 ; i < 1 ; i++){
            file.ignore(integer, '\n');
        }

        while(true){
            int v, u, wage;
            file >> v >> u >> wage;
            if( file.eof() ) break;
            this->wageMatrix[v][u] = wage;
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

void Graph::Print() {
    for (int v = 0; v < V; v++) {
        cout << "Vertex :" << v << " -> ";
        for (int i = 0; i < adjacencyList[v].size(); i++) {
            int x = adjacencyList[v].at(i);
            cout << x << " ";
        }
        cout << endl;
    }
}

void Graph::PrintWages() {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << this->wageMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
