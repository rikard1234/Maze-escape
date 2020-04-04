#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"
using namespace std;


int main() {
    int V, E;
    ifstream file;
    file.open("dane.txt");
    file >> V >> E;
    file.close();
    Graph graph(V, E);
    graph.ReadFromFile();
    graph.Print();
    graph.PrintWages();
    return 0;
}