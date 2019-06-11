#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"

//O(VLogV) 
//startVert zawsze 0?
int DijkstraList(ListGraph& test, int startVert);

void DijkstraMatrix(int** graph, int startVert, int size);

void printSolution(int dist[], int size);

#endif // !DIJKSTRA_HPP
