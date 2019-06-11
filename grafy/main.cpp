#include "graph.hpp"
#include "dijkstra.hpp"
#include "bellman_ford.hpp"
#include "tests.hpp"



// ListGraph graph{V};

// graph[v].push_back(neighbour);


int main()
{



	runTests();

	//GenerateGraphPerc(500, "kuba.txt", 100);

	//ListGraph test;
	//LoadGraphList(test, "kuba.txt");
	//DijkstraList(test, 0);

	std::cout << "\nFINISH\n";
	std::cin.get();
}


// 100 - liczba wierzcho³ków
// 1 10 5 15 (indeks waga)
// ...


/*
class Wierzcholek	//Vertex(==summit)
{
private:
	int element;
	int indeks;

public:
	//konstruktor jako lista inicjalizacyjna
	Wierzcholek() : element(0), indeks(0) {}	//bezparametrowy
	Wierzcholek(int element, int indeks)	//parametryczny > parametrowy (!)
	{
		this->element = element;
		this->indeks = indeks;
	}
};

class Krawedz	//Edge
{
private:
	int element;
	Wierzcholek poczatkowy;
	Wierzcholek koncowy;
	int indeks;

public:
	Krawedz() : element(0), poczatkowy(0, 0), koncowy(0, 0), indeks(0) {}
};

int main()
{
	Krawedz test;
	int i = 7;
}

*/