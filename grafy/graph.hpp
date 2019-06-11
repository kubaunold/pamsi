#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>	//do std::vector
#include <fstream>	//do tworzenia plikow
#include <ctime>	//do generowania liczb pseudolosowych
#include <algorithm>	//do sortowania
#include <string>
#include <sstream>		//do przetwarzania stringa na strumien?
#include <direct.h>	//do tworzenia katalogow

struct Neighbour {
	int index;
	int weight;

	Neighbour() : index(0), weight(0) {}
	
};

using ListGraph = std::vector<std::vector<Neighbour>>;
//using MatrixGraph = new int*

//size - ile graf ma miec wierzcholkow
//name - nazwa pliku, gdzie graf jest zapisany
void GenerateGraphPerc(int size, std::string name, int perc);


//zwroci obszar w pamieci, gdzie ten graf wirtualny zostanie utworzony
//name - nazwa pliku, gdzie graf jest zapisany
void LoadGraphList(ListGraph& graph, std::string name);

void LoadGraphMatrix(int** graph, std::string name);



#endif