#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"
#include "GraphLabyrinth.h"
using namespace std;


int main() {
    GraphLabyrinth lab("lab1.txt");
    vector<int> order = lab.bfs();
    for(int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }
    /*Graph lab2("dane2.txt");
    vector<int> order = lab2.dfs(6, 0);
    for(int i = 0; i < order.size(); i++) {
        cout << order[i];
    }
     */
}