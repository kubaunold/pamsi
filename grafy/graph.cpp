#include "graph.hpp"

void GenerateGraphPerc(int size, std::string name, int perc)
{
	double coeff = perc / 100.0;
	int genSize = int(coeff * size);

	//tworzenie katalogu, w ktorym zapisza sie wygenerowane grafy
	char dirName[] = "GeneratedGraphs";
	std::string dirNameS = "GeneratedGraphs";
	_mkdir(dirName);

	std::ifstream wejscie{ dirNameS + "\\" + name };

	//plik do zapisu grafy
	std::ofstream graphGen{ dirNameS + "\\" + name };

	////plik do zapisu grafy
	//std::ofstream graphGen{ dirNameS + "\\" + std::to_string(size) + '_' + std::to_string(perc) + "__" + name};

	//wpisanie rozmiaru grafu
	graphGen << size << std::endl;

	//pomocniczy ciag liczb 0, 1, ..., size
	int* row = new int[size];
	for (int i = 0; i < size; ++i)	row[i] = i;

	//std::numeric_limits<int>::min;

	//wype³nianie kolejnych wierzcholkow wazonymi krawedziami
	srand(int(time(NULL)));
	for (int i = 0; i < size; ++i)
	{
		graphGen << i << "\t\t";

		for (int j = 0; j < genSize; ++j)
		{
			//wagi grafow: 45 - 95
			graphGen << row[j] << ' ' << rand() % 51 + 45 << '\t';
		}
		//proba obejscia w LoadGraph
		//graphGen << "E";	//kazda linie koncz litera "E"

		//sortowanie wierzcholkow (pomocne)
		//std::sort(row, row + size);	//ta i next_perm sie wzajemnie wykluczaja!

		//wygenerowanie nowej permutacji na okreslonej tablicy
		std::next_permutation(row, row + size);

		graphGen << '\n';
	}

	graphGen.close();
}

void LoadGraphList(ListGraph& graph, std::string name)
{

	std::string dirNameS = "GeneratedGraphs";
	std::ifstream wejscie{ dirNameS + "\\" + name };


	if (wejscie)
	{
		std::string line;	//<stream>

		//utworzenie bufora z wczytanej linii
		std::getline(wejscie, line);
		std::istringstream row(line);	//<sstream>

		//wczytanie z pierwszej linii pliku --> rozmiar (liczba wierzcholkow) grafu
		unsigned int firstValSize;
		row >> firstValSize;
			

		while (std::getline(wejscie, line))
		{
			//utworzenie bufora z wczytanej linii
			std::istringstream row(line);	//<sstream>

			int noImportant;
			row >> noImportant;	//wczytanie indeksu wierzcholka

			//pomocniczy Neighbour do zapelniania currentRowa 
			Neighbour currentNeighbour;
			//pomocniczny vextor do zapelniania grafu glownego
			std::vector<Neighbour> currentRow;

			while (row >> currentNeighbour.index && row >> currentNeighbour.weight)
			{
			//	std::cout << o << '\t';	//wypisywanie na ekran
				currentRow.push_back(currentNeighbour);
			}

			//dodanie calego wczytanego wiersza
			graph.push_back(currentRow);
		}
	}

	//wejscie.close();
}

void LoadGraphMatrix(int** neo, std::string name)
{
	std::string dirNameS = "GeneratedGraphs";
	std::ifstream input{ dirNameS + "\\" + name };

	if (input)
	{
		std::string line;
		std::getline(input, line);
		std::istringstream row(line);

		unsigned int size;
		row >> size;

		int counter = 0;

		while (std::getline(input, line))
		{
			std::istringstream row(line);

			int ommit;
			row >> ommit;

			int index(-1), weight(-1);
			while (row >> index && row >> weight)
			{
				neo[counter][index] = weight;
			}

			counter++;
		}
	}


}