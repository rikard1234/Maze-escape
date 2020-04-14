#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"
using namespace std;


int main() {
    int V, E;

    Graph graph("dane.txt");
    graph.print();
    graph.printPensja();
    return 0;
}