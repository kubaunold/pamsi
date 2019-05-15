#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>


template <typename T>
class Lista
{

private:
	void ZwolnijMiejsce();
	
	//node - wezel
	struct Wezel
	{
		//inicjalizacja lista
		//konstruktor domyslny (dla nowotworzonego wezla)
		//a to nie jest przypadkiem kostruktor 1-parametrowy? (czyli NIEdomyœlny?)
		Wezel(const T& d) : nastepny(nullptr), poprzedni(nullptr), dane(d) {}

		Wezel* nastepny;
		Wezel* poprzedni;
		T dane;
	};

	//wskazniki na pierwszy wezel
	Wezel* glowa;
	Wezel* ogon;



public:
	////konstruktor
	//Lista() : glowa(nullptr), ogon(nullptr), licznik(0) {}

	//konstruktor analogicznie, ale bez listy inicjalizacyjnej
	Lista()
	{
		glowa = nullptr;
		ogon = NULL;
		licznik = 0;
	}

	//destuktor dla Listy
	~Lista() 
	{
		ZwolnijMiejsce();
	}



	struct Iterator
	{
		////domyslny konstruktor dla Iteratora
		//Iterator(Wezel* wezel = nullptr) : aktualny(wezel) {}

		// analogiczny konstruktor dla Iteratora
		Iterator(Wezel* wezel = nullptr)
		{			
			aktualny = wezel;
		}
		
		T& operator* ()
		{
			return aktualny->dane;
		}

		T* operator-> ()
		{
			return &aktualny->dane;
		}

		Iterator& operator++ ()
		{
			if (aktualny)
			{
				aktualny = aktualny->nastepny;
			}

			return *this;
		}

		Iterator& operator-- ()
		{
			if (aktualny)
			{
				aktualny = aktualny->poprzedni;
			}

			return *this;
		}

		//tutaj jeszcze 1xpre + 2xpost

		bool operator == (Iterator inny)
		{
			return aktualny == inny.aktualny;
		}
		
		bool operator != (Iterator inny)
		{
			return !(*this == inny);
		}

		Wezel* aktualny;
	};

	struct ConstIterator
	{
		//podwojny konstruktor (bez i paramtertryczny)
		ConstIterator(Wezel* wezel = nullptr) : aktualny(wezel) {}

		//ConstIterator(void) : aktualny(nullptr) {}
		//ConstIterator(Wezel* wezel) : aktualny(wezel) {}


		const T& operator* ()
		{
			return aktualny->dane;
		}

		const T* operator-> ()
		{
			return &aktualny->dane;
		}

		ConstIterator& operator++ ()
		{
			if (aktualny)
			{
				aktualny = aktualny->nastepny;
			}

			return *this;
		}

		ConstIterator& operator-- ()
		{
			if (aktualny)
			{
				aktualny = aktualny->poprzedni;
			}

			return *this;
		}

		//tutaj jeszcze 1xpre + 2xpost

		bool operator == (ConstIterator inny)
		{
			return aktualny == inny.aktualny;
		}

		bool operator != (ConstIterator inny)
		{
			return !(*this == inny);
		}

		Wezel* aktualny;
	};

	int licznik;

	void pushBack(const T& newElement);
	void pushFront(const T& newElement);
	void insert(const T& newElement, int index);
	void remove(const T& element);
	Iterator begin();
	Iterator end();
	ConstIterator cbegin() const;
	ConstIterator cend() const;
	T& operator [](int index);

	//std::ostream& operator<< (std::ostream& str, const Lista l);
	
};





template <typename TTT>
void Lista<TTT>::ZwolnijMiejsce()
{
	Wezel* aktualnyWezel = glowa;
	while (aktualnyWezel)
	{
		Wezel* temp = aktualnyWezel->nastepny;
		delete aktualnyWezel;
		aktualnyWezel = temp;
		licznik--;
	}
	glowa = ogon = NULL;
}

//dla szablonow definicje metod w .hpp



template <class T>
void Lista<T>::pushBack(const T& newElement)
{
	if (licznik++ == 0)
	{
		ogon = glowa = new Wezel(newElement);
	}

	else
	{
		Wezel* temp = ogon;
		ogon = new Wezel(newElement);
		temp->nastepny = ogon;
		ogon->poprzedni = temp;

		/*
		//bylo auto temp
		Wezel* temp = new Wezel(newElement);
		ogon->nastepny = temp;
		temp->poprzedni = ogon;
		ogon = temp;
		*/
		
	}
}

template <typename T>
void Lista<T>::pushFront(const T& newElement)
{
	if (licznik++ == 0)
	{
		ogon = glowa = new Wezel(newElement);
		
		//teraz juz niepotrzebna linijka, bo mam konstruktor parametryczny
		//glowa->dane = newElement;
		//analogicznie "->"
		//(*glowa).dane = newElement;
	}

	else
	{
		Wezel* temp = glowa;
		glowa = new Wezel(newElement);
		glowa->nastepny = temp;
		temp->poprzedni = glowa;
			   		 		
	}

	//takie cos zwraca fcja void
	return;
}

template <typename T>
void Lista<T>::insert(const T& newElement, int index)
{
	if (index > (licznik-1))
	{
		throw "index out of range";
	}
	
	auto nowyWezel = new Wezel(newElement);
	auto temp = glowa;
	for (int i = 0; i < index; ++i)
	{
		temp = temp->nastepny;
	}	

	auto beforeTemp = temp->poprzedni;

	nowyWezel->nastepny = temp;
	temp->poprzedni = nowyWezel;
	nowyWezel->poprzedni = beforeTemp;
	if (beforeTemp)
	{
		beforeTemp->nastepny = nowyWezel;
		
	}
	else glowa = nowyWezel;

		
}

template <typename T>
void Lista<T>::remove(const T& element)
{
	if(licznik == 0)
	{
		throw "Brak elementow w liscie";

	}

	else if (licznik > 0)
	{
		
		Wezel* current = glowa;
		while (current)
		{
			if (current->dane == element)
			{
				Wezel* toDelete = current;
				

				//ma wezel przed i po sobie (jest pomiedzy wezlami)
				if ((current->poprzedni) && (current->nastepny))
				{
					current = current->nastepny;

					toDelete->poprzedni->nastepny = toDelete->nastepny;
					toDelete->nastepny->poprzedni = toDelete->poprzedni;
					delete toDelete;
					licznik--;
				}

				//jest z lewego brzegu
				else if (!(current->poprzedni) && current->nastepny)
				{
					current = current->nastepny;

					current->poprzedni = NULL;
					delete toDelete;
					licznik--;
					glowa = current;
				}

				//jest z prawego brzegu
				else if (current->poprzedni && !(current->nastepny))
				{
					current = current->poprzedni;

					current->nastepny = NULL;
					delete toDelete;
					licznik--;
					ogon = current;


				}

			}

			else current = current->nastepny;
		}
	}
}

//po co tu to typename 2.?!
template <typename T>
typename Lista<T>::Iterator Lista<T>::begin()
{
	return Iterator(glowa);
}

template <typename T>
typename Lista<T>::Iterator Lista<T>::end()
{
	return Iterator();
}

template <typename T>
typename Lista<T>::ConstIterator Lista<T>::cbegin() const
{
	return ConstIterator(glowa);
}

template <typename T>
typename Lista<T>::ConstIterator Lista<T>::cend() const
{
	return ConstIterator();
}

template <typename T>
//co z tym typename?
/*typename*/ T& Lista<T>::operator [](int index)
{
	if (index > licznik) { throw "Indeks wychodzi poza rozmiar listy";  }
	else
	{
		int krokomierz(1);
		for (auto i = this->begin(); i != this->end(); ++i)
		{
			if (index == krokomierz)
			{
				return i.aktualny->dane;
				//std::cout << i->dane << "HAAA";
			}
			krokomierz++;
		}
		//????
		throw "Blad indeksu";
		//return *(new T);
	}
}

//nie dziala :( - throw exception
//template <class T>
//std::ostream& operator<< (std::ostream& str, const Lista<T> l)
//{
//
//	for (auto it = l.cbegin(); it != l.cend(); ++it)
//	{
//		str << *it;
//	}
//
//	return str;
//}

#endif