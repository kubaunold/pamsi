#include "dijkstra.hpp"


int minDistance(int distance[], bool sptSet[], int size)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < size; ++v)
	{
		if (sptSet[v] == false && distance[v] <= min)
			min = distance[v], min_index = v;
	}

	return min_index;
}

// A utility function to print the constructed distance array 
void printSolution(int dist[], int size)
{
	
	//printf("Vertex   Distance from Source\n");
	//for (int i = 0; i < size; i++)
	//	printf("%d \t\t %d\n", i, dist[i]);
	std::cout << ' ' <<size << std::endl;
}

int DijkstraList(ListGraph& test, int startVert)
{
	////OBYDWA PONIZEJ ZWRACAJA TO SAMO!
	//std::cout <<  int(std::numeric_limits<int>::max()) << std::endl;
	//std::cout << INT_MAX;

	int sizer = test.size();
	int* distance = new int[sizer];

	//list of visited vertices
	bool* sptSet = new bool[sizer];	//SPT - shortest path tree
	for (int i = 0; i < sizer; ++i)
		distance[i] = INT_MAX, sptSet[i] = false;

	distance[startVert] = 0;	//dist. from startVert is 0

	for (int count = 0; count < sizer - 1; ++count)
	{
		int u = minDistance(distance, sptSet, sizer);

		sptSet[u] = true;



		for (auto v : test[u])	//przejdz sie po wsyztskich sasiadach wierz. u
		{
			

			if (!sptSet[v.index] && distance[u] != INT_MAX && distance[u] + v.weight < distance[v.index])
				distance[v.index] = distance[u] + v.weight;
		}

		/*for (int v = 0; v < sizer; ++v)
			if (!sptSet[v] && 1)
				1;*/
	}



	
	std::cout << "DIJKSTRA_LIST";
	printSolution(distance, sizer);

	delete[] distance;
	delete[] sptSet;

	return 0;
}

void DijkstraMatrix(int** graph, int startVert, int size)
{
	int* distance = new int[size];
	bool* sptSet = new bool[size];	//SPT - shortest path tree
	for (int i = 0; i < size; ++i)
		distance[i] = INT_MAX, sptSet[i] = false;

	distance[startVert] = 0;	//dist. from startVert is 0

	for (int count = 0; count < size - 1; ++count)
	{
		int u = minDistance(distance, sptSet, size);

		sptSet[u] = true;

		//for (auto v : test[u])	//przejdz sie po wsyztskich sasiadach wierz. u
		//{


		//	if (!sptSet[v.index] && distance[u] != INT_MAX && distance[u] + v.weight < distance[v.index])
		//		distance[v.index] = distance[u] + v.weight;
		//}

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < size; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from  
			// u to v, and total weight of path from src to  v through u is  
			// smaller than current value of dist[v] 
			if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u] + graph[u][v];
	}

	
	std::cout << "DIJKSTRA_MATRIX";
	printSolution(distance, size);

	delete[] distance;
	delete[] sptSet;
}