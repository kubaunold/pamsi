#ifndef KOLEJKA_HPP
#define KOLEJKA_HPP

template <typename T>
class Queue
{
private:
	struct EQueue
	{
		EQueue(T d) : data(d), behind(nullptr) {}

		T data;
		EQueue* behind;
	};

	EQueue* head;	//wskazuje na glowa
	EQueue* tail;	//wskazuje na pierwszy WOLNY! element (nie na ostatni el. w kolejce)

public:
	Queue() : head(nullptr), tail(nullptr) {}

	//~Queue();

	void enqueue(const T& newElement);
	T dequeue();
	void show();
};

template <typename T>
void Queue<T>::enqueue(const T& newElement)
{
	EQueue* n = new EQueue(newElement);

	if (!head)	this->tail = this->head = n;
	else
	{
		this->tail->behind = n;
		this->tail = n;
	}

	return;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (!this->head) throw "Nothing to delete...";
	EQueue* toDelete = this->head;
	T inside = toDelete->data;
	this->head = this->head->behind;	//bylby wyciek pamieci gdyby byla tylko ta linijka w tej metodzie
	delete toDelete;
	
	return inside;
}

template <typename T>
void Queue<T>::show()
{
	EQueue* temp = this->head;
	while (temp != nullptr)
	{
		std::cout << temp->data << "   ";
		temp = temp->behind;
	}
	std::cout << std::endl;
}

#endif
