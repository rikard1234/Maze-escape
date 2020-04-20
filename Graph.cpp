//
// Created by Kuba on 03.04.2020.
//A{!tt
#include "Graph.h"
#include <queue>

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

vector<int> Graph::bfs(int n) {
    int* visited = new int [this->V];
    vector<int> order;
    for(int i = 0; i < this->V; i++)  visited[i] = false;
    queue<int> nodes;
    //init step
    visited[n] = true;
    nodes.push(n);
    //repetetive step
        while (!nodes.empty()) {
            n = nodes.front();
            order.push_back(n);
            for (int i = 0; i < adjacencyList[n].size(); i++) {
                if (!(visited[adjacencyList[n].at(i)])) nodes.push(adjacencyList[n].at(i));
            }
            nodes.pop();
            visited[n] = true;
            if(nodes.empty()) {
                for(int i; i < this->V; i++) {
                    if(visited[i] == false) {
                        nodes.push(i);
                        break;
                    }
                }
            }
        }
        return order;
}





















