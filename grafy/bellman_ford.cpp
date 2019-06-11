#include "bellman_ford.hpp"


void BellmanFordMatrix(int** matrix, int startVert, int size)
{
	//int edges = 0;
	//for (int i = 0; i < size; ++i)
	//{
	//	for (int j = 0; j < size; ++j)
	//		if (matrix[i][j])
	//			edges++;
	//}

	//Initialize all distances for infinity & dist[startVert] = 0
	int* dist = new int[size];
	for (int i = 0; i < size; ++i)
		dist[i] = INT_MAX;
	dist[startVert] = 0;

	//Relax all edges |V| - 1 times //V - # of vertices
	for (int r = 0; r < size - 1; ++r)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
				if (matrix[i][j])
				{
					int u = i;
					int v = j;
					int weight = matrix[i][j];
					if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
						dist[v] = dist[u] + weight;
				}
		}
	}


	std::cout << "BELLMAN_FORD_LIST";
	printSolution(dist, size);
	delete[] dist;
}

void BellmanFordList(ListGraph& test, int startVert, int size)
{
	//Initialize all distances for infinity & dist[startVert] = 0
	int* dist = new int[size];
	for (int i = 0; i < size; ++i)
		dist[i] = INT_MAX;
	dist[startVert] = 0;

	int u = std::distance(test.begin(), test.end()-1);

	//Relaxation V-1 times
	for (int i = 1; i <= size - 1; ++i)
	{
		for (int u = 0; u < size; ++u)
		{
			for (auto v : test[u])
			{
				int weight = v.weight;
				if (dist[u] != INT_MAX && dist[u] + weight < dist[v.index])
					dist[v.index] = dist[u] + weight;
			}
		}
	}


	std::cout << "BELLMAN_FORD_MATRIX";
	printSolution(dist, size);
	delete[] dist;
}