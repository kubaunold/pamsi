#ifndef BELLMAN_FORD_HPP
#define BELLMAN_FORD_HPP

#include "graph.hpp"
#include "dijkstra.hpp"

#include <iterator>

//O(VE)
//bidirectional edges ALWAYS!
void BellmanFordMatrix(int** matrix, int startVert, int size);


void BellmanFordList(ListGraph& test, int startVert, int size);
#endif // !BELLMAN_FORD_HPP

