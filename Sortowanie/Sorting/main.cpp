#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include "czas.h"

int content[1000] = { 10, 100, 1000, 3000, 7000, 10000, 30000, 50000, 70000, 100000, 200000 };

void generateTab(int rozmiar, std::string nazwaPliku);
void swap(int& a, int& b);
void swap(int& a, int& b, int& c);
void runTests();
void generateManyTabs();

class Sorter
{
private:
	int size;
	int* arr;
	int* sec;	//do MergeSorta
//
//	int AP(int left, int right)
//	{
//		//int v = tablica[(lewy + prawy) / 2];
//		int v = arr[left];
//		int i, j, x;
//		i = left;
//		j = right;
//		do
//		{
//			while (arr[i] < v) i++;
//			while (arr[j] > v) j--;
//			if (i <= j)
//			{
//				x = arr[i];
//				arr[i] = arr[j];
//				arr[j] = x;
//				i++;
//				j--;
//			}
//		} while (i <= j);
//
//		return j;
//
//	/*	int pivInd = left;
//		int pivot = arr[left];
//		int p = left + 1;
//		int q = right;
//		for (; left < right; )
//		{
//			if (arr[p] > pivot && arr[q] <= pivot)
//			{
//				swap(p, q, pivot);
//				pivInd = p;
//			}
//			if (arr[p] <= pivot) p++;
//			if (arr[q] > pivot) q--;
//		}
//
//		return pivInd;
//*/
//	/*	void partition(int *a, int size) {
//			int pivot = a[0];
//			int left, right;
//			for (left = 1, right = size - 1; left < right; )
//			{
//				if (a[left] > pivot && a[right] <= pivot)
//				{
//					swap(left, right, a);
//				}
//				if (a[left] <= pivot) left++;
//				if (a[right] > pivot) right--;
//			}
//		}*/
//		////ustawienie pivota na sztywno na pierwszy z lewej
//		//int pivInd = left;
//		//int pivVal = arr[left];
//		//int p = left; int q = right;
//		//while (p < q)
//		//{
//		//	while (arr[p] < pivVal && p < size)
//		//	{
//		//		p++;
//		//		
//		//	}
//		//	while (arr[q] > pivVal && q >= 0)
//		//	{
//		//		q--;
//		//		//std::cout << pivVal;
//		//	}
//
//		//	if (arr[size - 1] < pivVal) q = size - 1;
//
//		//	if (p < q)
//		//	{
//		//		if (p == pivInd) pivInd = q;
//		//		else if (q == pivInd) pivInd = p;
//
//		//		int temp = arr[p]; arr[p] = arr[q]; arr[q] = temp;
//		//	}
//		//}
//		//arr[left] = arr[q]; arr[q] = pivVal; pivInd = q;
//		//return pivInd;
//	}
//
public:
	Sorter() : size(0), arr(nullptr), sec(nullptr) {}
	Sorter(int number) : size(number), arr(new int[number /*+ 1*/]), sec(new int[number])
	{
		//arr[number] = -13;	//ustawienie wartownika
	}

	~Sorter()
	{
		delete[] arr;
		delete[] sec;
	}

	void load(std::string name)
	{
		std::ifstream loader{ "ManyTabsUnsorted\\" + name };
		loader >> size;
		for (int i = 0; i < size; ++i)
		{
			loader >> arr[i];
		}
		for (int i = 0; i < size; ++i)
		{
			sec[i] = -1;
		}
	}
	void show()
	{
		std::cout << "SHOWING ARRAY";
		std::cout << std::endl;
		for (int i = 0; i < 100; ++i) std::cout << '-';
		std::cout << std::endl;
		for (int i = 0; i < size; ++i) std::cout << arr[i] << '\t';
		std::cout << std::endl;
		for (int i = 0; i < 100; ++i) std::cout << '-';
		std::cout << std::endl;
	}
	void WriteToFile(std::string name, int size)
	{
		std::ofstream output{ "ManyTabsSorted\\" + name };
		output << size << '\n';
		for (int i = 0; i < size; ++i)
		{
			output << arr[i] << ' ';
		}
	}

	void BubbleSort()	// O(n^2)
	{

		//std::cout << "\nSORTING BY BUBBLESORT\n";
		int licznik = size;
		for (int j = 0; j < size; ++j)
		{
			for (int i = 0; i < licznik - 1; ++i)
			{
				if (arr[i] > arr[i + 1])
				{
					int temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
					//swap(arr[i], arr[i + 1]);
				}
			}
			licznik--;
		}
	}

	//void QuickSort(int l, int r)	// O(nlog_2^n); pesymistycznie: O(n^2)
	//{
	//	if (l == r) return;
	//	int pivotIndex = AP(l, r);
	//	QuickSort(l, pivotIndex);
	//	QuickSort(pivotIndex + 1, r);
	//}

	void QuickSort(int lewy, int prawy)
	{
		//pivot z polowy zakresu
		int v = arr[(lewy + prawy) / 2];

		int i = lewy;	//wskaznik poczatku
		int j = prawy;	//wskaznik konca
		do
		{
			while (arr[i] < v) i++;
			while (arr[j] > v) j--;
			if (i <= j)
			{
				int x = arr[i]; arr[i] = arr[j]; arr[j] = x;
				i++;
				j--;
			}
		} while (i <= j);
		if (j > lewy) QuickSort(lewy, j);
		if (i < prawy) QuickSort(i, prawy);
	}

	void MergeSort(int left, int right)	//	O(n*log_2^n)
	{
		if (left == right) return;
		int divide = (left + right) / 2;
		MergeSort(left, divide);
		MergeSort(divide + 1, right);
		//if (divide == 3 && right == 4)
		//{
		//	int q = 239476;
		//}
		Merge(left, divide, right);	//pamietaj o d+1
	}

	void Merge(int l, int d, int r)
	{
		int l1 = l;
		int l2 = d;
		int p1 = d + 1;
		int p2 = r;

		int secInd = l;
		int j = p1;

		if (l == 0 && r == 9)
		{
			int f = 5;
		}
		for (int i = l1; i <= l2; ++i)
		{
			while (arr[i] >= arr[j])
			{
				sec[secInd] = arr[j]; j++; secInd++;

				if (j == p2 + 1)
				{
					//przepisz reszte z L
					while (i <= l2)
					{
						sec[secInd] = arr[i]; secInd++;
						++i;

					}
					for (int i = l; i <= r; ++i)	arr[i] = sec[i];	//1/2
					return;
				}
			}
			sec[secInd] = arr[i]; secInd++;
		}

		if (sec[j] == -1) sec[j] = arr[j];

		for (int i = l; i <= r; ++i)
		{
			arr[i] = sec[i];	//dla ostatniego mergowania
		}


	}

};

int main()
{


	//generateManyTabs();
	//runTests();


	Sorter qs(50000);
	clock_t start, stop;
	
	qs.load("SortMe50000_v0.txt");	//!sama nazwa!

	start = clock();
	qs.BubbleSort();
	stop = clock();
	//qs.show();
	std::cout << stop - start << " ms" << std::endl;
	std::cout << "_done_";
	std::cin.get();
}

void generateTab(int size, std::string name)	//do stringa postrzbny #include <string>
{

	if (name[name.size() - 1] == 't' && name[name.size() - 2] == 'x' && name[name.size() - 3] == 't' &&name[name.size() - 4] == '.')
	{
		std::ofstream toSort{ "ArrsToSort\\" + name };	//fstream (ofstream)
		toSort << size << std::endl;

		srand(unsigned int(time(NULL)));	//ctime
		for (int i(1); i <= size; ++i)
		{
			toSort << rand() % 100 << '\t';
		}
	}
	else
	{
		std::ofstream toSort{ "ArrsToSort\\" + name + ".txt" };	//fstream (ofstream)

		toSort << size << std::endl;

		srand(unsigned int(time(NULL)));	//ctime
		for (int i(1); i <= size; ++i)
		{
			toSort << rand() % 100 << '\t';
		}
	}

}
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

void generateManyTabs()
{
	for (int j = 0; content[j] != '\0'; ++j)
	{
		int size = content[j];
		//std::cout << content[i] << ' ';
		for (int i = 0; i < 10; ++i)
		{
			std::string nazwa = "SortMe";
			nazwa.append(std::to_string(size) + "_v" + std::to_string(i) + ".txt");	//wypluwa nazwy typu "SortMe10_v3.txt"
			//std::cout << nazwa << ' ';

			//ladowanie tablicy randomowymi size*liczbami
			std::ofstream otwarty{ "ManyTabsUnsorted\\" + nazwa };
			otwarty << size << '\n';
			for (int i(1); i <= size; ++i)
			{

				otwarty << rand() % 100 << '\t';
			}
			otwarty.close();
			std::cout << nazwa << " - done" << '\n';
		}
	}


	//int s = 0;
	//const int rozmiarTablicy = 50;	//50 znakow na nazwe pliku
	//char tab[rozmiarTablicy] = "SortMe";
	//const int indOne = int('1');

	////name.append("z");	//dodawanie na koniec stringa
	//
	//for (; s < rozmiarTablicy; ++s)
	//{
	//	if (tab[s] == '\0') break;
	//}

	//srand(time(NULL));	//ctime

	//for (int i = 1; i <= 10; ++i)
	//{
	//	if (i == 10)
	//	{
	//		tab[s] = '1', tab[s + 1] = '0';
	//	}
	//	else
	//	{
	//		tab[s] = char(indOne + i - 1);
	//	}
	//	

	//	std::string roboczoString = tab;
	//	std::ofstream currentFile{"ManyTabs\\10\\" + roboczoString + ".txt" };

	//	//10x10 el.
	//	int size = 10;
	//	currentFile << size << std::endl;
	//	

	//	for (int i(1); i <= size; ++i)
	//	{

	//		currentFile << rand() % 100 << '\t';
	//	}

	//	//std::cout << tab << ' ';
	//}
	//

	//std::string str = std::to_string(42);
	//std::ofstream rt{ "ManyTabs\\10\\" + str + ".txt" };

}

void runTests()
{
	//std::ofstream xd{ "XD1.txt"};
	std::ofstream zerowanko{ "Times\\BubbleSort.csv"};
	zerowanko.clear();
	zerowanko.close();

	std::ofstream halko{ "Times\\QuickSort.csv" };
	halko.clear();
	halko.close();

	std::ofstream emet{ "Times\\MergeSort.csv" };
	emet.clear();
	emet.close();

	for (int j = 0; content[j] != '\0'; ++j)
	{
		int size = content[j];
		for (int i = 0; i < 10; ++i)
		{
			std::string nazwa = "SortMe";
			nazwa.append(std::to_string(size) + "_v" + std::to_string(i) + ".txt");	//wypluwa nazwy typu "SortMe10_v3.txt"

			Sorter workingOn(size);	//powolanie do zycia obiektu klasy sorter

			
			
			{//bubble sort
				std::cout << "BUBBLE SORT -> " << nazwa << ' ' << j << "/" << 10 << '\n';
				workingOn.load(nazwa);	//zaladowanie tablicy wygenerowanymi wczesniej liczbami

				//clock_t start, stop;
				//start = clock();
				Czas czasDzialania;
				czasDzialania.czasStart();
				workingOn.BubbleSort();	//posortowanie bubblesortem
				//stop = clock();
				czasDzialania.czasStop();
				printf("Czas wykonywania: %lu ns\n\n", czasDzialania.czasWykonania());

				workingOn.WriteToFile(nazwa, size);	//zapis do pliku	//aby pokazac, ze inne sortuja, przenies te linijke pod pozostale sortowania

				//zapis czasu wykonywania sortowania
				std::fstream czasBubble{ "Times\\BubbleSort.csv", std::ios::out | std::ios::app };
				czasBubble << size << ";"  << czasDzialania.czasWykonania() << '\n';
				czasBubble.close();

			}

			{//qs
				std::cout << "QUICK SORT -> " << nazwa << ' ' << j << "/" << 10 << '\n';
				workingOn.load(nazwa);	//zaladowanie tablicy wygenerowanymi wczesniej liczbami

				Czas czasDzialania;
				czasDzialania.czasStart();
				workingOn.QuickSort(0, size - 1);	//posortowanie quicksortem
				czasDzialania.czasStop();
				printf("Czas wykonywania: %lu ns\n\n", czasDzialania.czasWykonania());

				std::fstream czasQuick{ "Times\\QuickSort.csv", std::ios::out | std::ios::app};
				czasQuick << size << ";"  << czasDzialania.czasWykonania() << '\n';
				czasQuick.close();
			}

			{//ms
				std::cout << "MERGE SORT -> " << nazwa << " ---" << j << "/" << 10 << "---" << '\n';
				workingOn.load(nazwa);	//zaladowanie tablicy wygenerowanymi wczesniej liczbami

				Czas czasDzialania;
				czasDzialania.czasStart();
				workingOn.MergeSort(0, size - 1);	//posortowanie mergesortem
				czasDzialania.czasStop();
				printf("Czas wykonywania: %lu ns\n\n", czasDzialania.czasWykonania());

				std::fstream czasMerge{ "Times\\MergeSort.csv", std::ios::out | std::ios::app};
				czasMerge << size << ";"  << czasDzialania.czasWykonania() << '\n';
				czasMerge.close();
			}



			////ladowanie tablicy randomowymi size*liczbami
			//std::ofstream otwarty{ "ManyTabsUnsorted\\" + nazwa };
			//otwarty << size << '\n';
			//for (int i(1); i <= size; ++i)
			//{

			//	otwarty << rand() % 100 << '\t';
			//}
			//otwarty.close();
			//std::cout << nazwa << " - done" << '\n';
		}
	}




	//std::cout << "\n\nRunning tests for BubbleSort\n\n";

	////std::ifstream pracujacy{ "ManyTabsUnsorted\\SortMe10_v0.txt" };
	//Sorter _sorter(10);
	//_sorter.load("SortMe10_v0.txt");
	//_sorter.BubbleSort();
	//std::ofstream wyjscie{ "ManyTabsSorted\\Sorted10_v0.txt" };
	//_sorter.WriteToFile("Sorted10_v0.txt", 10);
	//wyjscie << 10 << '\n';
	//for (int 1 = 0; i < size; ++i)
	//{
	//	_sorter.W
	//}
	//_sorter.show();



	//	void load(std::string name)
	//{
	//	std::ifstream loader{ "ArrsToSort\\" + name };
	//	loader >> size;
	//	for (int i = 0; i < size; ++i)
	//	{
	//		loader >> arr[i];
	//	}
	//	for (int i = 0; i < size; ++i)
	//	{
	//		sec[i] = -1;
	//	}
	//}

	/*
	int size = 100;
	std::string name = "123.txt";

	generateTab(size, name);
	Sorter trial(size);
	trial.load(name);
	trial.show();
	//trial.QuickSort(0, size-1);
	//trial.BubbleSort();
	trial.MergeSort(0, size - 1);
	trial.show();
	*/



}

void swap(int& a, int& b, int& c)
{
	int temp = b;
	b = a;
	a = c;
	c = temp;
}