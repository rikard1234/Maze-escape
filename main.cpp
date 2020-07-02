#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"
using namespace std;


int main() {
    vector<int> order;
    Graph graph("dane2.txt");
    graph.print();
    order = graph.bfs(0);

    for(int i = 0; i < order.size(); i++){
        //cout << order.size() << " ";
        cout << order[i] << " ";
    }
    return 0;
}