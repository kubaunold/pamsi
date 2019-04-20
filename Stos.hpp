#ifndef STOS_HPP
#define	STOS_HPP

template <class T>
class Stos
{
private:
	struct EStosu
	{
		//ten dwukropek za konstruktorem mowi, ze bede uzywal listy inicjalizacyjnej
		//lista inicjalizacyjna wykonje sie ZANIM obiekt zacznie istniec
		//kostruktor wykonuje sie gdy obiekt juz istnieje
		//PROTIP: gdzie mozesz uzywaj listy inicjalizacyjnej
		EStosu(T d) : dane(d), dolny(NULL) {}

		T dane;
		EStosu* dolny;
	};

	EStosu* wierzch;
	int licznik;

public:
	Stos() : wierzch(NULL), licznik(0) {}
	~Stos();

	void push(const T& newElement);
	T pop();
	void pokazStos();
};

template <typename T>
 void Stos<T>::push(const T& newElement)
{
	 EStosu* temp = wierzch;
	 EStosu* nowy = new EStosu(newElement);
	 this->wierzch = nowy;
	 nowy->dolny = temp;
	 licznik++;
}

 template <typename T>
 T Stos<T>::pop()
 {
	 if (wierzch == NULL) return 0;

	 EStosu* temp = wierzch;
	 T doZwrotu = wierzch->dane;
	 wierzch = wierzch->dolny;
	 delete temp;
	 licznik--;

	 return doZwrotu;
 }

 template<class T>
 void Stos<T>::pokazStos()
 {
	 EStosu* temp = wierzch;
	 while (temp != NULL)
	 {
		 std::cout << temp->dane << std::endl << "|" << std::endl;
		 temp = temp->dolny;
	 }
	 std::cout << "NULL\n\n\n";
 }

 template<class T>
 Stos<T>::~Stos()
 {
	 EStosu* temp = wierzch;
	 while (temp != NULL)
	 {
		 wierzch = wierzch->dolny;
		 delete temp;
		 licznik--;
		 temp = wierzch;
	 }
 }













#endif