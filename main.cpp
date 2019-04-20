//smart formatowanie wierszy
//ctrl k ctrl f




//moja lista dwukierunkowa
#include "Lista.hpp"
//lista z STL (Standard Template Library)
#include <list>

#include "Stos.hpp"
#include <stack>

#include "Kolejka.hpp"
#include <queue>

#include "KolejkaPriorytetowa.hpp"
//kolejka priorytetowa jest w <queue> lib

#include "TablicaZHaszowaniem.hpp"
#include <map>



void TestujLista()
{
	Lista <int> list;
	list.pushBack(3);
	list.pushFront(7);
	list.pushBack(35);
	list.insert(999, 1);

	//auto przyjmuje automatycznie potrzebny typ
	//w tym przypadku bedzie to: "Lista<int>::Iterator it"

	for (auto element : list)
	{
		std::cout << element << " ";
	}

	for (auto it = list.cbegin(); it != list.cend(); ++it)
	{
		std::cout << *it;
	}
}
void KubaTest()
{
	Lista<int> list;

	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushBack(4);
	list.pushBack(5);

	std::cout << std::endl << list[3] << std::endl;
	//list.pushFront(1);
	//list.pushBack(1);
	//list.pushFront(1);
	//list.pushBack(4);

	//list.remove(1);
	//list.~Lista();
	for (Lista<int>::Iterator iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		std::cout << *iterator << " ";
	}
}
void ListaSTL()
{
	std::list<int> listaSTL;	//utworzenie listy przechowujacej inty

	listaSTL.push_front(5); //na poczatek wepchnie 5
	listaSTL.push_front(17);
	listaSTL.push_front(23);
	listaSTL.push_front(98);

	listaSTL.push_back(-3);	//na koniec doda -3

	//usunie element z konca
	listaSTL.pop_back();

	//wymaze poprzedni wpis i wpisze 4 jedynki
	listaSTL.assign(4, 1);

	//umiesci 15 na poczatku
	listaSTL.insert(listaSTL.begin(), 15);

	//umiesci 25 siodemek na poczatku
	listaSTL.insert(listaSTL.begin(), 25, 7);

	//usunie wszytskie wezly o indeksie 1
	listaSTL.remove(1);

	//std::SetConsoleAttribute(std::GetStdHandle(std::STD_OUTPUT_HANDLE), 10);
	//wypisanie zawartosci listy
	for (std::list<int>::iterator i = listaSTL.begin(); i != listaSTL.end(); ++i)
	{
		std::cout << *i << " ";
	}
}

void TestujStos()
{
	Stos<int> stax;
	stax.push(5);
	stax.push(6);
	stax.push(2);

	//stax.pokazStos();

	//stax.pop();
	//stax.pokazStos();
	//stax.pop();
	//stax.pop();
	//stax.pop();
	//stax.pop();
	//stax.pop();
	//stax.pop();
	//stax.pop();
	//stax.pokazStos();
}
void StosSTL()
{
	std::stack<int> stek;
	stek.push(9);
	stek.push(7);
	stek.push(2);
	stek.push(1);
	stek.push(-3);
	stek.push(-5);


	size_t f = stek.size();	//dziala jak int
	for (int i = 1; i <= f; ++i)
	{
		std::cout << stek.top() << std::endl;
		stek.pop();
	}
	
}

void TestujKolejka()
{
	Queue<int> kolejka;
	kolejka.enqueue(5);
	kolejka.enqueue(6);
	kolejka.enqueue(2);
	kolejka.show();
	kolejka.dequeue();
	kolejka.show();
	kolejka.dequeue();
	kolejka.dequeue();
	//kolejka.dequeue();
	//kolejka.dequeue();
}
void KolejkaSTL()
{
	std::queue<int> kolejka;
	kolejka.push(5);
	kolejka.push(6);
	kolejka.push(2);
	
	size_t rozmiar = kolejka.size();
	for (int i = 1; i <= rozmiar; ++i)
	{
		std::cout << kolejka.front();
		kolejka.pop();
	}
}

void TestujKolejkaPriorytetowa()
{
	PriorityQueue<int> kolejka;
	kolejka.enqueue(5, 10);
	kolejka.enqueue(6, 7);
	kolejka.enqueue(2, 3);
	kolejka.enqueue(3, 4);
	kolejka.enqueue(20, 20);
	kolejka.enqueue(40, 40);
	kolejka.enqueue(69, -5);

	kolejka.show();

	kolejka.dequeue();
	kolejka.show();
	//
	kolejka.dequeue(); kolejka.dequeue(); kolejka.dequeue(); kolejka.show();

	//kolejka.dequeue(); kolejka.dequeue(); kolejka.dequeue(); kolejka.dequeue(); kolejka.dequeue(); kolejka.show();
}
void KolejkaPriorytetowaSTL()
{
	std::priority_queue<int> kolejkaP;
	kolejkaP.push(5);
	kolejkaP.push(70);
	kolejkaP.push(-13);
	kolejkaP.push(12);
	kolejkaP.push(100);
	kolejkaP.push(1);

	while (!kolejkaP.empty())
	{
		std::cout << kolejkaP.top() << " ";
		kolejkaP.pop();
	}
}

void TestujTablicaZHaszowaniem()
{
	//Map<int, int> mapI;
	Map<std::string, int> mapS;
	
	//mapI.insert(15, 5);
	mapS.insert("Kuba", 2);
	mapS.insert("Ala", 7);
	mapS.insert("Ewa", 665);
	mapS.insert("Olek", -12);

	std::cout << "***" << mapS("Kuba") << "***" << std::endl;
	mapS.remove("Kuba");
	std::cout << "***" << mapS("Kuba") << "***" << std::endl;
	
	
}

void TablicaZHaszowaniemSTL()
{
	std::map<std::string, int> mapa;
	//mapa.insert("Kuba", 2);
	mapa["Kuba"] = 3;
	std::cout << mapa["Kuba"] << std::endl;
	mapa.clear();
	std::cout << mapa["Kuba"] << std::endl;
}

int main()
{
	
	/*TESTOWANIE LISTY*/
	//TestujLista();
	//KubaTest();
	//ListaSTL();	//ta z STL'a nie ma indeksowania

	/*TESTOWANIE STOSU*/
	//TestujStos();
	//StosSTL();

	/*TESTOWANIE KOLEJKI*/
	//TestujKolejka();
	//KolejkaSTL();

	/*TESTOWANIE KOLEJKI PRIORYTETOWEJ*/
	//TestujKolejkaPriorytetowa();
	//KolejkaPriorytetowaSTL();

	/*TESTOWANIE TABLICY Z HASZOWANIEM*/
	//TestujTablicaZHaszowaniem();
	TablicaZHaszowaniemSTL();

	std::cin.get();// std::cin.get();
	//domyslnie return 0
}
