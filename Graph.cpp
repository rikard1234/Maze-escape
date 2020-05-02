//
// Created by Kuba on 03.04.2020.
//A{!tt
#include "Graph.h"
#include <queue>
#include <stack>

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
    bool* visited = new bool [this->V];
    vector<int> order;
    for(int i = 0; i < this->V; i++) {
        visited[i] = false;
    }
    queue<int> nodes;
    //init step
    nodes.push(n);
    visited[n] = true;
    //repetetive step
        while (!nodes.empty()) {
            n = nodes.front();
            order.push_back(n);
            nodes.pop();
            for (int i = 0; i < adjacencyList[n].size(); i++) {
                if (!(visited[adjacencyList[n].at(i)]) ) {
                    visited[adjacencyList[n].at(i)] = true;
                    nodes.push(adjacencyList[n].at(i));
                }
            }
            if(nodes.empty()) {
                for(int i = 0; i < this->V; i++) {
                    if(visited[i] == false) {
                        visited[i] = true;
                        nodes.push(i);
                        break;
                    }
                }
            }

        }
        return order;
}

vector<int> Graph::dfs(int n) {
    bool visited[this->V];
    stack<int> nodes;
    for(int i = 0; i < this->V; i++) visited[i] = false;
    vector<int> order;
    nodes.push(n);
    visited[nodes.top()] = true;
    while(!nodes.empty()) {
        n = nodes.top();
        order.push_back(n);
        nodes.pop();
        for (int i = 0; i < adjacencyList[n].size(); i++) {
            if (!visited[adjacencyList[n].at(i)]) {
                nodes.push(adjacencyList[n].at(i));
                visited[adjacencyList[n].at(i)] = true;
            }
        }
        if(nodes.empty()) {
            for(int i = 0; i < this->V; i++) {
                if(visited[i] == false) {
                    visited[i] = true;
                    nodes.push(i);
                    break;
                }
            }
        }
    }
    return order;
}




















