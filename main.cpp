#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"
#include "GraphLabyrinth.h"
using namespace std;


int main() {
    GraphLabyrinth lab("lab1.txt");

    vector<pair<int, float>> order = lab.a();
    vector<int> orderd = lab.dfs();
    vector<int> orderb = lab.bfs();

    for(int i = 0; i < order.size(); i++) {
        cout << order[i].first<< " ";
    }
    cout << endl;

    for(int i = 0; i < orderb.size(); i++) {
        cout << orderb[i] << " ";
    }
    cout << endl;

   for(int i = 0; i < orderd.size(); i++) {
      cout << orderd[i] << " ";
    }
}