#include "tests.hpp"

void runTests()
{
	//4 poziomy zapelnienia	|	5 roznych wielkosci | 10x
	int graphPerc[] = { 25, 50, 75, 100 };
	int graphSize[] = {10, 100/*, 250, 350, 500, 700*/};
	int repeat = 1;
	std::string name = "graphex.txt";
	std::string outputFileName[] = { "dijkstra_list.csv", "dijkstra_matrix.csv", "bellman_ford_list.csv", "bellman_ford_matrix.csv" };

	char dirName[] = "Results";
	std::string dirNameS = "Results";
	_mkdir(dirName);

	/*
	1) generuje konkretny graf (1 z 4*5*100 == 1/2000)
	2) lecê go na 4 sposoby
	3) czas kazdego sposoby zapisuje w oddzielnych 4 plikach (appendix!)
	*/
	std::ofstream out;
	for (std::string n : outputFileName)
	{
		out.open("Results\\" + n, std::ios::trunc);
		out.close();
	}



	for (int percentage : graphPerc)
	{
		for (int size : graphSize)
		{
			for (int counter = 0; counter < repeat; ++counter)
			{

				GenerateGraphPerc(size, name, percentage);
				

				//DIJKSTRA_LIST
				ListGraph DL;
				LoadGraphList(DL, name);
				
				Czas czasDzialaniaDL;
				czasDzialaniaDL.czasStart();
				DijkstraList(DL, 0);
				czasDzialaniaDL.czasStop();

				out.open("Results\\" + outputFileName[0], std::ios::app);
				out << size << ';' << percentage << ';' << czasDzialaniaDL.czasWykonania() << std::endl;
				out.close();

				//DIJKSTRA_Matrix
				int** DM = new int*[size];
				for (int i = 0; i < size; ++i)
					DM[i] = new int[size];
				for (int i = 0; i < size; ++i)
					for (int j = 0; j < size; ++j)
						DM[i][j] = 0;

				LoadGraphMatrix(DM, name);
				Czas czasDzialaniaDM;
				czasDzialaniaDM.czasStart();
				DijkstraMatrix(DM, 0, size);
				czasDzialaniaDM.czasStop();

				out.open("Results\\" + outputFileName[1], std::ios::app);
				out << size << ';' << percentage << ';' << czasDzialaniaDM.czasWykonania() << std::endl;
				out.close();

				//BELLMAN_FORD_LIST
				ListGraph BFL;
				LoadGraphList(BFL, name);

				Czas czasDzialaniaBFL;
				czasDzialaniaBFL.czasStart();
				BellmanFordList(BFL, 0, size);
				czasDzialaniaBFL.czasStop();

				out.open("Results\\" + outputFileName[2], std::ios::app);
				out << size << ';' << percentage << ';' << czasDzialaniaBFL.czasWykonania() << std::endl;
				out.close();

				//BELLMAN_FORD_MATRIX
				int** BFM = new int*[size];
				for (int i = 0; i < size; ++i)
					BFM[i] = new int[size];
				for (int i = 0; i < size; ++i)
					for (int j = 0; j < size; ++j)
						BFM[i][j] = 0;

				LoadGraphMatrix(BFM, name);
				Czas czasDzialaniaBFM;
				czasDzialaniaBFM.czasStart();
				BellmanFordMatrix(BFM, 0, size);
				czasDzialaniaBFM.czasStop();

				out.open("Results\\" + outputFileName[3], std::ios::app);
				out << size << ';' << percentage << ';' << czasDzialaniaBFM.czasWykonania() << std::endl;
				out.close();

			}
		}
	}





}






//void runTests()
//{
//	//POLE WYPELNIA UZYTKOWNIK
//	//*******************************
//	//unsigned int size = 10;
//	std::string name = "geeks.txt";
//	int perc = 20;	//% zape³nienie grafu
//	int startVert = 0;	//startowy wierzcholek to ten z ind. 0
//	//*******************************
//
//	//GenerateGraphPerc(size, name, perc);
//
//	//***********************************************
//	//DIJKSTRA - LISTA SASIEDZTWA
//	//ListGraph test/*{ size }*/;
//	//LoadGraphList(test, name);
//	//DijkstraList(test, startVert);
//	//***********************************************
//
//
//	//***********************************************
//	//DIJKSTRA - MATRIX
//	//int ** matrix = new int* [9] ;
//	//for (int i = 0; i < 9; ++i)
//	//	matrix[i] = new int[9];
//	//for (int i = 0; i < 9; ++i)
//	//	for (int j = 0; j < 9; ++j)
//	//		matrix[i][j] = 0;
//
//	//LoadGraphMatrix(matrix, name);
//	//DijkstraMatrix(matrix, startVert, 9);
//	//***********************************************
//
//	//***********************************************
//	//BELLMAN_FORD - LISTA SASIEDZTWA
//	ListGraph test;
//	LoadGraphList(test, name);
//	BellmanFordList(test, startVert, 9);
//	//***********************************************
//
//	//***********************************************
//	//BELLMAN_FORD - MATRIX 
//	//int ** matrix = new int*[9];
//	//for (int i = 0; i < 9; ++i)
//	//	matrix[i] = new int[9];
//	//for (int i = 0; i < 9; ++i)
//	//	for (int j = 0; j < 9; ++j)
//	//		matrix[i][j] = 0;
//
//	//LoadGraphMatrix(matrix, name);
//	//BellmanFordMatrix(matrix, startVert, 9);
//	//***********************************************
//}

