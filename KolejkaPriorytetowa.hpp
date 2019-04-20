#ifndef KOLEJKA_PRIORYTETOWA_HPP
#define KOLEJKA_PRIORYTETOWA_HPP

template <typename T>
class PriorityQueue
{
private:
	struct Node
	{
		Node(const T& newElement, int priority) : data(newElement), preference(priority), behind(nullptr) {}
		Node(Node* copy)
		{
			this->data = copy->data;
			this->preference = copy->preference;
			this->behind = copy->behind;
		}
		T data;
		int preference; //pierwszenstwo, preferencja, uprzywilejowanie
		Node* behind;

	};

	Node* head{ nullptr };
	Node* tail{ nullptr };

public:
	//PriorityQueue() : head(nullptr), tail(nullptr) {};
	~PriorityQueue();

	
	void enqueue(const T& newElement, int priority);
	T dequeue();
	//void Priorise();
	void show();
};


template <typename T>
void PriorityQueue<T>::enqueue(const T& newEle, int prio)
{
	Node* toAdd = new Node(newEle, prio);

	if (!head && !tail) head = tail = toAdd;
	else
	{
		//Node* temp = head;
		//this->head = toAdd;
		//toAdd->behind = temp;
		////delete temp;	//nie moge tego zrobic, bo usune to, co jest pod tym wskaznikiem, a to jest wazne! to element mojej kolejki!
		////w tym momencie nowy wezel jest na poczatku kolejki (staje sie nowa glowa)
		//if(head->preference < head->behind->preference) Priorise();

		if (head->preference <= toAdd->preference)	//jesli przyjdzie dodac na poczatku kolejki
		{
			toAdd->behind = head;
			head = toAdd;
		}
		else
		{
			if (tail->preference > toAdd->preference)	//jesli przyjdzie nam dodac na koniec kolejki
			{
				tail->behind = toAdd;
				tail = toAdd;
				return;
			}
			else  //dodawanie pomiedzy
			{
				Node* comparator = head->behind;
				Node* compPlusOne = head;
				while (comparator->preference > toAdd->preference)
				{
					comparator = comparator->behind;
					compPlusOne = compPlusOne->behind;
				}

				toAdd->behind = comparator;
				compPlusOne->behind = toAdd;

			}
		}
		

	}
}

//template <typename T>
//void PriorityQueue<T>::Priorise()
//{
//
//	
//	if (head->behind->behind == nullptr)	//gdy mamy jedynie 2 elementy w kolejce
//	{
//		Node* newHead = head->behind;
//		head->behind->behind = head;
//		head->behind = nullptr;
//		head = newHead;
//		//std::cout << "WSZEDLBYM";
//	}
//
//	else
//	{
//		Node* x = new Node(head);	//setting new Node pointer 'x' to count how many changes are neccesary
//		int counter(0);
//		while ((x->preference < x->behind->preference) && x->behind!=nullptr)
//		{
//			counter++;
//			x->behind = x->behind->behind;
//		}
//
//		for (int i(1); i <= counter; ++i)
//		{
//			x->behind = head->behind; //x ustawiam przed glowa, zeby miec dostep do glowy i tego za glowa
//
//			T dTemp=x->behind->behind->data;
//			int pTemp=x->behind->behind->data;
//			x->behind->behind->data = x->behind->data;
//			x->behind->behind->preference = x->behind->preference;
//			x->behind->data = dTemp;
//			x->behind->preference = pTemp;
//
//			x->behind = x->behind->behind;
//		}
//
//	}
//	//else std::cout << "NIE WSZEDLBYM";
//
//
//	//T tempData = one->data;
//	//two->data = one->data;
//	//one->data = tempData;
//
//	//int tempPrio = one->preference;
//	//two->preference = one->preference;
//	//one->preference = tempPrio;
//}

template <typename T>
void PriorityQueue<T>::show()
{
	Node* temp = head;
	std::cout << "\n+++++++++++++++++++++++++++++++++++++\n";
	while (temp)
	{
		std::cout << temp->data << "\n";
		temp = temp->behind;
	}
	std::cout << "\n+++++++++++++++++++++++++++++++++++++\n";
}


template <typename T>
 PriorityQueue<T>::~PriorityQueue()
{
	 while (head)
	 {
		 Node* toDelete(head);
		 head = head->behind;
		 delete toDelete;
	 }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
	if (!head) throw "Empty PriorityQueue";
	else
	{
		T dTemp = head->data;
		if (head == tail)	//gdy 1 element w kolejce
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* toDelete(head);
			head = head->behind;
			delete toDelete;
		}

		return dTemp;
	}

}

#endif // !KOLEJKA_PRIORYTETOWA_HPP