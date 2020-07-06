//
// Created by Kuba on 03.04.2020.
//A{!tt
#include "Graph.h"
#include <queue>
#include <stack>

Graph::Graph() {}
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
    bool* visited = new bool[this->V];
    vector<int> order;
    deque<int> nodes;
    this->init(n, visited, nodes);

    while (!nodes.empty()) {
        n = nodes.back();
        nodes.pop_back();
        order.push_back(n);
        this->visitNeighbors(n, visited, nodes);
        this->checkForUnvisitedNode(visited, nodes);
    }

    return order;
}

vector<int> Graph::dfs(int n) {
    bool* visited = new bool[this->V];
    deque<int> nodes;
    vector<int> order;
    this->init(n, visited, nodes);

    while(!nodes.empty()) {
        n = nodes.front();
        nodes.pop_front();
        order.push_back(n);
        this->visitNeighbors(n, visited, nodes);
        this->checkForUnvisitedNode(visited, nodes);
    }

    return order;
}

void Graph::init(int n, bool* visited, deque<int>& nodes) {
    for(int i = 0; i < this->V; i++) {
        visited[i] = false;
    }
    nodes.push_front(n);
    visited[n] = true;
}

void Graph::visitNeighbors(int n, bool* visited, deque<int>& nodes) {
    for (int i = 0; i < adjacencyList[n].size(); i++) {
        if (!(visited[adjacencyList[n].at(i)]) ) {
            visited[adjacencyList[n].at(i)] = true;
            nodes.push_front(adjacencyList[n].at(i));
        }
    }
}

void Graph::checkForUnvisitedNode(bool* visited, deque<int>& nodes) {
    if(nodes.empty()) {
        for(int i = 0; i < this->V; i++) {
            if(visited[i] == false) {
                visited[i] = true;
                nodes.push_front(i);
                break;
            }
        }
    }
}


















