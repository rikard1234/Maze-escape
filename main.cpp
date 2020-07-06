#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"
#include "GraphLabyrinth.h"
using namespace std;


int main() {
    GraphLabyrinth lab("lab1.txt");
    lab.displayAdjacencyList();

}